package nyp08;
public enum Tariff {
	NETFREE(0,4,60), NET4(4,8,30), NET6(6,8,40);
	private int quota, speed, fee;
	private Tariff( int quota, int speed, int fee ) {
		this.quota = quota; this.speed = speed; this.fee = fee;
	}
	public int getQuota() { return quota; }
	public int getSpeed() { return speed; }
	public int getFee() { return fee; }
	public void setFee(int newFee) { fee = newFee; }
	public String toString() {
		return "Quota: " + quota + ", speed: " + speed + 
				", fee: " + fee;
	}
}
