package nyp09;

import java.io.*;

public class ExceptionExample01 {
	MyScreenRenderer graphics; 
	MyCADfile myFile;
	//Other methods of this class are omitted
	public void parseMyCADfile( String fileName ) {
		try {
			graphics = new MyScreenRenderer(); 
			myFile = openFile( fileName );
			MyFigure figs[ ] = myFile.readFromFile( );
			drawFigures( figs );
			myFile.close();
		}
		catch( IOException e ) {
			System.out.println("An IO exception has occurred " + 
				"while opening or reading from file:" + 
				e.getMessage( ) );
			e.printStackTrace( );
			System.exit(1);
		}
		finally {
			graphics.releaseSources();
		}
	}
	
	public MyCADfile openFile( String fileName ) {
		return null;
	}
	
	public void drawFigures( MyFigure[] figs ) {
		
	}
	 

}

abstract class MyCADfile extends java.io.InputStream {
	public abstract MyFigure[] readFromFile( );
}

class MyFigure {

}

class MyScreenRenderer {
	public void releaseSources() {
		
	}
	
}