package batuhanodcikin;

public class Applicant {
	private String name;
	private String passportName;
	private boolean hasWorkPermit;
	public Applicant(String name, String passportName, boolean hasWorkPermit) {
		this.name = name;
		this.passportName = passportName;
		this.hasWorkPermit = hasWorkPermit;
	}
	public String getName() {
		return name;
	}
	public String getPassportName() {
		return passportName;
	}
	public boolean isHasWorkPermit() {
		return hasWorkPermit;
	}
	
	@Override
	public String toString() {
		return "Applicant [name=" + name + ", passportName=" + passportName + ", hasWorkPermit=" + hasWorkPermit + "]";
	}
	
}
