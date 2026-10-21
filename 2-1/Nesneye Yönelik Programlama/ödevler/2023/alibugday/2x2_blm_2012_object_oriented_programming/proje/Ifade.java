package NYO_proje_19011076;
import java.util.Arrays;

public class Ifade implements java.io.Serializable{
	private static final long serialVersionUID = 1L;
	private final int columnCount;
	private static int currentRow = 0;
	private String[] harfler;
	private String[] renkler;
	private String kelime;
	
	public Ifade(String kelime) {
		this.kelime = kelime;
		columnCount = kelime.length();
		harfler = kelime.split("");
		renkler = new String[columnCount];
		for(int i=0;i<columnCount;i++) {
			renkler[i] = "grey";
		}
	}

	
	

	public String[] getHarfler() {
		return harfler;
	}




	public String[] getRenkler() {
		return renkler;
	}




	public String getKelime() {
		return kelime;
	}



	public static int getCurrentRow() {
		return currentRow;
	}



	public static void setCurrentRow(int currentRow) {
		Ifade.currentRow = currentRow;
	}



	public int getColumnCount() {
		return columnCount;
	}

	@Override
	public String toString() {
		return "Ifade [columnCount=" + columnCount + ", currentRow=" + currentRow + ", harfler="
				+ Arrays.toString(harfler) + ", renkler=" + Arrays.toString(renkler) + "]";
	}

	public void changeColor(int i, int j) {
		String[] gecici = {"grey", "yellow", "green"};
		renkler[i] = gecici[j];
	}	
	
	public boolean isContain(String str) {
		for(String iter:harfler) {
			if(iter.compareTo(str)==0) {
				return true;
			}
		}
		return false;
	}
	
	public void compareto(Ifade kiyas) {
		for(int i=0;i<kiyas.harfler.length;i++) {
			if(kiyas.harfler[i].equals(harfler[i])) {
				changeColor(i, 2);
			}
			if(this.harfler[i].equals(kiyas.harfler[i]) == false) {
				if(isContain(kiyas.harfler[i])) {
					//System.out.println("flag:" + kiyas.harfler[i] + "-" + harfler[i]);
					kiyas.changeColor(i, 1);
				}
			}
		}
	}
	
	public boolean isWin(){
		for(int i=0;i<getColumnCount();i++) {
			if(!renkler[i].equals("green")) {
				return false;
			}
		}
		return true;
	}
	
	@SuppressWarnings("static-access")
	public static void main(String[] args) {
        String equation = "12+36=46";
        Ifade obje = new Ifade(equation);
        Ifade obje2 = new Ifade("45+23=78");
        obje2.setCurrentRow(2);
        
        obje2.compareto(obje);
        obje.compareto(obje2);
        
        System.out.println(obje2);
        System.out.println(obje);
    }
	

	
	
	
}
