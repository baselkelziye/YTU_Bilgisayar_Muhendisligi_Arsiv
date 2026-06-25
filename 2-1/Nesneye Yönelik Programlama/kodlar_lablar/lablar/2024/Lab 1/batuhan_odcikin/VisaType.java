package batuhanodcikin;

public class VisaType {

	private String type;
	private int maxStayDuration;
	private boolean requiresWorkPermit;
	
	
	public VisaType(String type, int maxStayDuration, boolean requiresWorkPermit) {
		this.type = type;
		this.maxStayDuration = maxStayDuration;
		this.requiresWorkPermit = requiresWorkPermit;
	}
	
	public String getType() {
		return type;
	}
	
	public int getMaxStayDuration() {
		return maxStayDuration;
	}
	
	public boolean isWorkPermitRequired() {
		return requiresWorkPermit;
	}
	
	@Override
	public String toString() {
		return "VisaType [type=" + type + ", maxStayDuration=" + maxStayDuration + ", requiresWorkPermit="
				+ requiresWorkPermit + "]";
	}
	
	
	
}
