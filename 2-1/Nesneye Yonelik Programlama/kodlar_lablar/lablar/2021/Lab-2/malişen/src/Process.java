
public class Process {
	private String name;
	private int required_memory;
	private User user;
	public Process(String name, int required_memory ,User user) {
		this.name=name;
		this.required_memory=required_memory;
		this.user=user;
	}
	public String getName() {
		return this.name;
	}
	public int getRequiredMemory() {
		return this.required_memory;
	}
	public User getUser(){
		return this.user;
	}
	@Override
	public String toString() {
		return "Process [name=" + name + ", required_memory=" + required_memory + ", user=" + user + "]";
	}

}
