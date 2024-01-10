
public interface IPorcessManager {
	public int getUsed_memory_size();
	public boolean add_process(User u, String processname, int required_memory);
	public boolean remove_process(String name) throws Exception;
	public void print_processes();
	public void print_waiting_processes();
}
