#pragma once
#include "eyex\EyeX.h"
#include "Windows.h"

/// Clase que maneja la interacción con el dispositivo TobiiEyeX
/**
	Esta clase crea las instancias y manejadores necesarios para interactuar con
	los eventos básicos del TobiiEyeX
*/
class EyeXHost {

public:

	/// Se implementa este método para que las instancias del manejador sean únicas
	static EyeXHost *instance(HWND hwndWindow)
	{
		if (singleton == NULL)
			singleton = new EyeXHost(hwndWindow);
		return singleton;
	}

	static int x;
	static int y;

private:

	static HWND hwndWindow;

	/// Constructor de la clase
	explicit EyeXHost(HWND);

	/// Destructor de la clase
	/*
		Termina las conexiones con el TobiiEyeX
	*/
	virtual ~EyeXHost();

	/// ID del interactor
	static const TX_STRING InteractorId;

	static TX_HANDLE g_hGlobalInteractorSnapshot;

	TX_CONTEXTHANDLE hContext;
	TX_TICKET hConnectionStateChangedTicket;
	TX_TICKET hEventHandlerTicket;

	/// Callback del manejo de eventos de mirada del usuario
	static void OnGazeDataEvent(TX_HANDLE);

	TX_RESULT InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE);
	
	static void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE, TX_USERPARAM);
	static void TX_CALLCONVENTION OnEngineConnectionStateChanged(TX_CONNECTIONSTATE, TX_USERPARAM);
	static void TX_CALLCONVENTION HandleEvent(TX_CONSTHANDLE, TX_USERPARAM);


private: 

	/// Instancia del singleton
	static EyeXHost *singleton;

	class EyeXHostSingletonGuard {
	public:
		~EyeXHostSingletonGuard() {
			if (EyeXHost::singleton != NULL)
				delete EyeXHost::singleton;
		}
	};
	
	friend class EyeXHostSingletonGuard;
};
