#include "EyeXHost.h"

//#include <QtCore/QDebug>

EyeXHost *EyeXHost::singleton = NULL;
const TX_STRING EyeXHost::InteractorId = "EyeX Qt";
TX_HANDLE EyeXHost::g_hGlobalInteractorSnapshot = TX_EMPTY_HANDLE;
HWND EyeXHost::hwndWindow = NULL;
int EyeXHost::x = 0;
int EyeXHost::y = 0;

EyeXHost::EyeXHost(HWND _hwndWindow)
	: hContext(TX_EMPTY_HANDLE)
	, hConnectionStateChangedTicket(TX_INVALID_TICKET)
	, hEventHandlerTicket(TX_INVALID_TICKET)
{
	hwndWindow = _hwndWindow;

	//qRegisterMetaType<Sample>("Sample");
	bool success = true;

	success &= TX_RESULT_OK == txInitializeEyeX(TX_EYEXCOMPONENTOVERRIDEFLAG_NONE, NULL, NULL, NULL, NULL);
	success &= TX_RESULT_OK == txCreateContext(&hContext, TX_FALSE);
	success &= TX_RESULT_OK == InitializeGlobalInteractorSnapshot(hContext);
	success &= TX_RESULT_OK == txRegisterConnectionStateChangedHandler(
		hContext,
		&hConnectionStateChangedTicket,
		&EyeXHost::OnEngineConnectionStateChanged,
		NULL);
	success &= TX_RESULT_OK == txRegisterEventHandler(hContext, &hEventHandlerTicket, &EyeXHost::HandleEvent, NULL);
	success &= TX_RESULT_OK == txEnableConnection(hContext);
	if (success)
		printf("Tobii EyeX Initialization was successful.\n");

}


EyeXHost::~EyeXHost()
{
	printf("Shutting down EyeXHost ...\n");
	txDisableConnection(hContext);
	txReleaseObject(&g_hGlobalInteractorSnapshot);
	txShutdownContext(hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE);
	txReleaseContext(&hContext);
}


TX_RESULT EyeXHost::InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext)
{
	TX_RESULT result;
	TX_HANDLE gazeInteractor = TX_EMPTY_HANDLE;
	TX_GAZEPOINTDATAPARAMS gazeParams = { TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED };
	result = txCreateGlobalInteractorSnapshot(hContext, InteractorId, &g_hGlobalInteractorSnapshot, &gazeInteractor);
	if (result == TX_RESULT_OK) {
		result = txCreateGazePointDataBehavior(gazeInteractor, &gazeParams);
		txReleaseObject(&gazeInteractor);
	}
	return result;
}


void TX_CALLCONVENTION EyeXHost::OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param)
{
	TX_RESULT result = TX_RESULT_UNKNOWN;
	txGetAsyncDataResultCode(hAsyncData, &result);
	//Q_ASSERT(result == TX_RESULT_OK || result == TX_RESULT_CANCELLED);
}


void TX_CALLCONVENTION EyeXHost::OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState, TX_USERPARAM userParam)
{
	bool success;
	switch (connectionState) {
	case TX_CONNECTIONSTATE_CONNECTED:
		printf("The connection state is now CONNECTED (We are connected to the EyeX Engine)\n");
		success = TX_RESULT_OK == txCommitSnapshotAsync(g_hGlobalInteractorSnapshot, &EyeXHost::OnSnapshotCommitted, NULL);
		if (success)
			printf("Waiting for gaze data to start streaming...\n");
		else
			printf("Failed to initialize the data stream.\n");
		break;
	case TX_CONNECTIONSTATE_DISCONNECTED:
		printf("The connection state is now DISCONNECTED (We are disconnected from the EyeX Engine)\n");
		break;
	case TX_CONNECTIONSTATE_TRYINGTOCONNECT:
		printf("The connection state is now TRYINGTOCONNECT (We are trying to connect to the EyeX Engine)\n");
		break;
	case TX_CONNECTIONSTATE_SERVERVERSIONTOOLOW:
		printf("The connection state is now SERVER_VERSION_TOO_LOW: this application requires a more recent version of the EyeX Engine to run.\n");
		break;
	case TX_CONNECTIONSTATE_SERVERVERSIONTOOHIGH:
		printf("The connection state is now SERVER_VERSION_TOO_HIGH: this application requires an older version of the EyeX Engine to run.\n");
		break;
	}
}


void EyeXHost::OnGazeDataEvent(TX_HANDLE hGazeDataBehavior)
{
	TX_GAZEPOINTDATAEVENTPARAMS eventParams;
	if (TX_RESULT_OK == txGetGazePointDataEventParams(hGazeDataBehavior, &eventParams)) {
		POINT point = { (long)eventParams.X, (long)eventParams.Y };
		ScreenToClient(hwndWindow, &point);
		x = point.x;
		y = point.y;
	}
}


void TX_CALLCONVENTION EyeXHost::HandleEvent(TX_CONSTHANDLE hAsyncData, TX_USERPARAM userParam)
{
	TX_HANDLE hEvent = TX_EMPTY_HANDLE;
	TX_HANDLE hBehavior = TX_EMPTY_HANDLE;

	txGetAsyncDataContent(hAsyncData, &hEvent);

	if (TX_RESULT_OK == txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_GAZEPOINTDATA)) {
		OnGazeDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}

	txReleaseObject(&hEvent);
}