package lab2_19011076;

import java.io.IOException;

@SuppressWarnings("serial")
public class Hata extends IOException {
	public Hata( String errorMessage ) { 
		super(errorMessage); 
	}
}
