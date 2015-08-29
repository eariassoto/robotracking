#include "conexionYun.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"
#include "Poco/RegularExpression.h"

using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::Exception;
using Poco::RegularExpression;

conexionYun::conexionYun(string s){
	conf.loadFile(s);
	direccionBase = "http://" + conf.getValue("configuraciones:ip", "") + "/";
	cout << direccionBase << endl;
}

string conexionYun::enviarPeticion(string req){
	try
	{
		string strURI = direccionBase + req;
		URI uri(strURI);
		string path(uri.getPathAndQuery());
		if (path.empty()) path = "/";

		HTTPClientSession session(uri.getHost(), uri.getPort());
		HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
		session.sendRequest(req);
		HTTPResponse res;

		istream& rs = session.receiveResponse(res);
		//cout << res.getStatus() << " " << res.getReason() << endl;

		string result;
		StreamCopier::copyToString(rs, result);
		//cout << result << endl;

		return result;
	}
	catch (Exception& exc)
	{
		cerr << exc.displayText() << endl;
		return "";
	}
}