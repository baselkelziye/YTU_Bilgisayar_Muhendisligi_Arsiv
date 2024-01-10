import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.*;

public class ProcessManager implements IPorcessManager{
	int used_memory_size;
	int max_memory_size;
	HashMap<String,Process> processMaps;
	LinkedList<Process> waitingProcessList;
	public ProcessManager(int max_memory_size) {
		processMaps = new HashMap<String,Process>();
		waitingProcessList = new LinkedList<Process>();
		used_memory_size=0;
		this.max_memory_size=max_memory_size;
	}
	public boolean add_process(User u, String processname, int required_memory) {
		Process p=new Process(processname,required_memory,u);
		if(required_memory+used_memory_size<=max_memory_size && !processMaps.containsKey(processname)) {
			used_memory_size+=required_memory;
			processMaps.put(processname, p);
			return true;
		}
		if(!processMaps.containsKey(processname)) {
			waitingProcessList.add(p);
			return true;
		}
		return false;
		
	}
	public int getUsed_memory_size() {
		return used_memory_size;
		
	}
	public void print_processes() {
        for(Entry<String,Process> p:processMaps.entrySet()){
            System.out.println(p.getValue().getName()+" -> "+p.getValue().toString());
        }
    }
	public void	print_waiting_processes() {
		Iterator<Process> itr = waitingProcessList.iterator();
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
	}
	public boolean remove_process(String name) throws Exception{
		if(processMaps.containsKey(name)) {
			throw new Exception("Process not found");
		}
		else {
			used_memory_size-=processMaps.get(name).getRequiredMemory();
			processMaps.remove(name);
			Iterator<Process> itr = waitingProcessList.iterator();
			while(itr.hasNext() && used_memory_size<=max_memory_size ) {
				Process my=itr.next();
				waitingProcessList.remove(my);
				add_process( my.getUser(),  my.getName(), my.getRequiredMemory());
			}
			return true;
		}
		
	}
}
