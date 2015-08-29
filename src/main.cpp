#include "ofMain.h"
#include "ofApp.h"

int main(){

	ofSetWorkingDirectoryToDefault();	

	int x = 1280;
	int y = 720;
	ofSetupOpenGL(x, y, OF_WINDOW);

	/*sqlite3Manager s("data/db/robotracking.db3");
	vector<vector<string>> r = s.executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Acciones'");
	s.printTable(r);
	*/
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp(x, y));
	

}
