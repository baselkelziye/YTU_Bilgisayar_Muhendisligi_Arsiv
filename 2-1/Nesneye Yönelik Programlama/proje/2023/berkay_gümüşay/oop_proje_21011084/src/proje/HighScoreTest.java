package Proje;

import static org.junit.Assert.*;
import static org.junit.jupiter.api.Assertions.assertEquals;

import java.io.IOException;

import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.jupiter.api.BeforeEach;

public class HighScoreTest {
	private fileOperations fileOps;
	
	@BeforeEach
    public void setUp() {
        fileOps = new fileOperations();
    }
	
	@Test
	public void testHighScore() throws IOException {
		int control = 0;
		int exception = 0;
		fileOps = new fileOperations();
		String[][] scoreMatrix = fileOps.highScores("0", "0", "0");
		for (int i = 0 ; i<(scoreMatrix.length)-1 ; i++) {
			if(Integer.parseInt(scoreMatrix[i][2]) < Integer.parseInt(scoreMatrix[i+1][2])) {
				control = 1;
			}
		}
		assertEquals(exception,control);
	}

}
