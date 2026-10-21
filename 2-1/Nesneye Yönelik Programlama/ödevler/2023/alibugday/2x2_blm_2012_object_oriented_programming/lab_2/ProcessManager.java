package lab2_19011076;
import java.util.*;
import java.util.Map.Entry;

public class ProcessManager implements IProcessManager{
	private int used_memory_size;
	private final int max_memory_size;
	LinkedList<Process> waitingProcessList;
	HashMap<String, Process> processMaps;
	
	
	public ProcessManager(int max_memory_size) {
		this.max_memory_size = max_memory_size;
		this.waitingProcessList = new LinkedList<Process>();
		this.processMaps = new HashMap<String, Process>();
	}


	public int getUsed_memory_size() {
		return used_memory_size;
	}


	public void setUsed_memory_size(int used_memory_size) {
		this.used_memory_size = used_memory_size;
	}


	public int getMax_memory_size() {
		return max_memory_size;
	}

	
	public boolean add_process(User u, String processname, int required_memory) {
		Process isleyen = new Process(processname, required_memory, u);
		if(getUsed_memory_size() + required_memory <= getMax_memory_size()) {
			processMaps.put(processname, isleyen);
			setUsed_memory_size(getUsed_memory_size() + required_memory);
			return true;
		}
		else {
			waitingProcessList.add(isleyen);
			return false;
		}
		
		//Process isleyen = new Process(processname, required_memory, u);
	}


	public boolean remove_process(String name) throws Hata {
		if(processMaps.get(name) != null) {
			setUsed_memory_size(getUsed_memory_size() - processMaps.get(name).getRequired_memory());
			processMaps.remove(name);
			
			for(Process i:waitingProcessList) {
				if(i.getRequired_memory()+getUsed_memory_size() <= getMax_memory_size()) {
					add_process(i.getUser(), i.getName(), i.getRequired_memory());
					break;
				}
			}
			return true;
		}
		else {
			throw new Hata("Process cannot found");
		}
		
	}


	@Override
	public void print_processes() {
		for (Entry<String, Process> m : processMaps.entrySet()) {
			System.out.println(m.getValue() + ", " + m.getKey());
		}
	}


	@Override
	public void print_waiting_processes() {
		Iterator<Process> itr = waitingProcessList.iterator();
		
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
	}
	
	
	
}
