package tr.edu.yildiz.payci.soner.DAL;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.StringJoiner;

public class SqlBuilder implements ISqlBuilder {
    @Override
    public String BuildCreateTableCommand(String tableName, HashMap<String, String> createSpec ) {

        /*
        String CREATE_USERS_TABLE = "CREATE TABLE " + TABLE_USERS +
            "(" +
                KEY_USER_ID + " INTEGER PRIMARY KEY," +
                KEY_FIRST_NAME + " TEXT," +
                KEY_LAST_NAME + " TEXT," +
                KEY_USERNAME + " TEXT," +
                KEY_PASSWORD + " TEXT," +
                KEY_AVATAR + " TEXT," +
                KEY_EMAIL + " TEXT," +
                KEY_PHONE + " TEXT," +
                KEY_DATE_OF_BIRTH + " TEXT" +
            ")";


        * */
        StringJoiner joiner = new StringJoiner(" ,");

        String sql = String.format("CREATE TABLE %s ", tableName);

        String keysSection = "( %s );";

        Iterator iterator = createSpec.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry keyValuePair = (Map.Entry)iterator.next();
            String joinerStr = " %s %s ";
            joiner.add(String.format(joinerStr, keyValuePair.getKey(), keyValuePair.getValue()));
            iterator.remove();
        }

        sql += String.format(keysSection, joiner.toString());
        System.out.println(String.format("SQL : %s", sql));
        return sql;
    }

    @Override
    public String BuildUpdateTableCommand() {
        return null;
    }

    @Override
    public String BuildDeleteTableCommand() {
        return null;
    }

    @Override
    public String BuildSelectCommand(String tableName, ArrayList<String> selectColumns, HashMap<String, String> whereParams) {
        String selectColumnsSql = String.join(", ", selectColumns) + " ";
        String sql = String.format("SELECT %s FROM %s ", selectColumnsSql, tableName);

        if (whereParams != null) {
            sql += " WHERE";
            StringJoiner joiner = new StringJoiner(" AND");
            Iterator iterator = whereParams.entrySet().iterator();
            while (iterator.hasNext()) {
                Map.Entry keyValuePair = (Map.Entry)iterator.next();
                String joinerStr = !iterator.hasNext() ? " %s='%s' " : " %s='%s'";
                joiner.add(String.format(joinerStr, keyValuePair.getKey(), keyValuePair.getValue().toString()));
                iterator.remove();
            }
            sql += joiner.toString();
        }
        return sql;
    }
    @Override
    public String BuildSelectCommand(String tableName, ArrayList<String> selectColumns, HashMap<String, String> whereParams, HashMap<String, String> joinParams) {
        String selectColumnsSql = String.join(", ", selectColumns) + " ";
        String sql = String.format("SELECT %s FROM %s ", selectColumnsSql, tableName);

        if (joinParams != null) {
            sql += " LEFT JOIN ";
            StringJoiner joiner = new StringJoiner(" AND");
            Iterator iterator = joinParams.entrySet().iterator();
            while (iterator.hasNext()) {
                Map.Entry keyValuePair = (Map.Entry)iterator.next();
                String joinerStr = !iterator.hasNext() ? " %s ON  %s.%s=%s.id " : " %s ON  %s=%s.id";
                //keyValuePair.getKey() => joined table name     QUESTION_MEDIAS
                //keyValuePair.getValue() => joined table column name // QUESTION_ID
                joiner.add(String.format(joinerStr, keyValuePair.getKey(), keyValuePair.getKey(), keyValuePair.getValue(), tableName));
                iterator.remove();
            }
            sql += joiner.toString();
        }

        if (whereParams != null) {
            sql += " WHERE";
            StringJoiner joiner = new StringJoiner(" AND");
            Iterator iterator = whereParams.entrySet().iterator();
            while (iterator.hasNext()) {
                Map.Entry keyValuePair = (Map.Entry)iterator.next();
                String joinerStr = !iterator.hasNext() ? " %s='%s' " : " %s='%s'";
                joiner.add(String.format(joinerStr, keyValuePair.getKey(), keyValuePair.getValue().toString()));
                iterator.remove();
            }
            sql += joiner.toString();
        }
        return sql;
    }

    @Override
    public String BuildSelectQuestionsCommand() {
       String sql = "SELECT  Q.*, QM.* FROM Questions Q LEFT JOIN QuestionMedias QM ON (QM.questionId = Q.id) Where Q.userId=%d";
       return sql;
    }

    public String BuildSelectQuestionsByExamIdCommand() {
       String sql = "SELECT  Q.*, QM.* FROM QuestionsExams QE " +
               "INNER JOIN Questions Q ON (Q.id = QE.questionId) " +
               "LEFT JOIN QuestionMedias QM ON (QM.questionId = Q.id) " +
               "Where QE.examId=%d";
       return sql;
    }

    public String BuildSelectExamsCommand() {
        return "SELECT * FROM Exams Where userId=%d;";
    }

    @Override
    public String BuildInsertCommand(String tableName, ArrayList<String> insertSpec) {
        /*
        String CREATE_USERS_TABLE = "INSERT INTO TABLE_USERS" +
            "(KEY_FIRST_NAME, KEY_LAST_NAME, KEY_USERNAME, KEY_PASSWORD, KEY_AVATAR, KEY_EMAIL, KEY_PHONE, KEY_DATE_OF_BIRTH, KEY_AVATAR)" +
            "VALUES (?, ?, ?, ....);
        */

        StringJoiner keysJoiner = new StringJoiner(", ");
        StringJoiner valuesJoiner = new StringJoiner(", ");

        String sql = String.format("INSERT INTO %s ", tableName);

        String keysSection = " ( %s )";
        String valuesSection = " VALUES ( %s );";

        for (String key: insertSpec) {
            keysJoiner.add(key);
            valuesJoiner.add("?");
        }

        sql += String.format(keysSection, keysJoiner.toString()) + " " + String.format(valuesSection, valuesJoiner.toString());

        System.out.println(String.format("SQL : %s", sql));
        return sql;
    }

    @Override
    public String BuildUpdateCommand() {
        return null;
    }

    @Override
    public String BuildDeleteCommand(String tableName, HashMap<String, Integer> whereParams) {

        return null;
    }
}
