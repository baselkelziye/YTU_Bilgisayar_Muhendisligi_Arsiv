package tr.edu.yildiz.payci.soner.DAL;

import java.util.ArrayList;
import java.util.HashMap;

public interface ISqlBuilder {

    public String BuildCreateTableCommand(String tableName, HashMap<String, String> createSpec);

    public String BuildUpdateTableCommand();

    public String BuildDeleteTableCommand();

    public String BuildSelectQuestionsCommand();

    public String BuildSelectCommand(String tableName, ArrayList<String> selectColumns, HashMap<String, String> whereParams);

    public String BuildSelectCommand(String tableName, ArrayList<String> selectColumns, HashMap<String, String> whereParams, HashMap<String, String> joinParams);

    public String BuildInsertCommand(String tableName, ArrayList<String> insertSpec);

    public String BuildUpdateCommand();

    public String BuildDeleteCommand(String tableName, HashMap<String, Integer> whereParams);







}
