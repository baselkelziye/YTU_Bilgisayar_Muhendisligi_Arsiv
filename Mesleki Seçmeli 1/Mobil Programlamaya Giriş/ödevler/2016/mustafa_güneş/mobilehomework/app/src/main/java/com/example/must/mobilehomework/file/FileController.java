package com.example.must.mobilehomework.file;

import android.content.ContentValues;
import android.content.Context;
import android.widget.Toast;

import com.example.must.mobilehomework.SignUpActivity;
import com.example.must.mobilehomework.model.Car;
import com.example.must.mobilehomework.model.DateSelection;
import com.example.must.mobilehomework.model.Log;
import com.example.must.mobilehomework.model.RentDate;
import com.example.must.mobilehomework.model.RentSelection;
import com.example.must.mobilehomework.model.User;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by must on 30.04.2016.
 */
public class FileController {
    private final static String USER_FILE_NAME = "users.txt";
    private final static String CAR_FILE_NAME = "cars.txt";
    private final static String LOG_FILE_NAME = "logs.txt";

    public List<Car> getFreeCars(Context c, RentSelection rt){

        //Tüm arabaları çekip tarihi ve şehri uygun olanları döndür
        List<Car> carList = getAllCars(c);
        List<Car> returnList = new ArrayList<>();

        //Log listesinde o arabaya ait kayıt varsa seçemesin
        for(int i=0; i<carList.size(); i++){
            //eğer şehir doğruysa ve log kaydı yoksa ve istenen tipteyse
            if(isLogExist(carList.get(i).getId(), c) == false) {
                if(carList.get(i).getLocationCity().contains(rt.getPickupCity())){
                    if(carList.get(i).getType().equalsIgnoreCase(rt.getCarType())){
                        returnList.add(carList.get(i));
                    }

                }
            }

        }

        return returnList;
    }

    //o idye ait arabanın log kaydı var mı
    public boolean isLogExist(int id, Context context){
        String line;
        String [] split;

        try{
            InputStream inputStream = context.openFileInput(LOG_FILE_NAME);

            if ( inputStream != null ) {
                InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                while ((line = bufferedReader.readLine()) != null ) {
                    split = line.split(" ");
                    if(id == Integer.parseInt(split[0])){
                       return true;
                    }
                }

                inputStream.close();
            }
        }
        catch(FileNotFoundException nfe){
            Toast.makeText(context, "logs.txt Dosya Bulunamadı", Toast.LENGTH_SHORT).show();
            return false;
        }
        catch (IOException io){
            Toast.makeText(context, "logs.txt Okuma hatası", Toast.LENGTH_SHORT).show();
            return false;
        }

        return false;
    }

    //Verilen car id yi içeren kayıtları getir
    public List<Log> getCarLogList(int id, Context context){
        List<Log> logList = new ArrayList<>();
        String line;
        String [] split;

        try{
            InputStream inputStream = context.openFileInput(CAR_FILE_NAME);

            if ( inputStream != null ) {
                InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                while ((line = bufferedReader.readLine()) != null ) {
                    split = line.split(" ");
                    if(id == Integer.parseInt(split[0])){
                        Log log = new Log();
                        logList.add(log);
                    }
                }

                inputStream.close();
            }
        }
        catch(FileNotFoundException nfe){
            Toast.makeText(context, "logs.txt Dosya Bulunamadı", Toast.LENGTH_SHORT).show();
        }
        catch (IOException io){
            Toast.makeText(context, "logs.txt Okuma hatası", Toast.LENGTH_SHORT).show();
        }

        return logList;
    }

    //Kiralama kaydını dosyaya yazdır
    public boolean saveLog(Log log, Context context){
        try{
            OutputStreamWriter outputStreamWriter = new OutputStreamWriter(
                    context.openFileOutput(LOG_FILE_NAME, Context.MODE_APPEND));

            outputStreamWriter.write(log.getCarId()+" "); //arabanın idsi
            outputStreamWriter.write(log.getUser()+" "); //kiralayan kullanıcı
            outputStreamWriter.write(log.getPickupCity()+" "); //arabayı aldığı şehir
            outputStreamWriter.write(log.getDropoffCity()+" ");//arabayı bırakacağı yer
            outputStreamWriter.write(log.getDate().getPickupMonth()+" "); //aldığı ay
            outputStreamWriter.write(log.getDate().getPickupDay()+" ");//aldığı gün
            outputStreamWriter.write(log.getDate().getDropoffDay()+" "); //bırakacağı ay
            outputStreamWriter.write(log.getDate().getDropoffDay()+" ");//bırakacağı gün
            outputStreamWriter.write("\n");
            outputStreamWriter.flush();
        }
        catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(context, "Log Kaydında Bir hata meydana geldi", Toast.LENGTH_SHORT).show();
            return false;
        }

        return true;
    }

    public List<Car> getAllCars(Context context){
        List<Car> carList = new ArrayList<>();

        String line;
        String [] split;

        try{
            InputStream inputStream = context.openFileInput(CAR_FILE_NAME);

            if ( inputStream != null ) {
                InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                while ((line = bufferedReader.readLine()) != null ) {
                    split = line.split(" ");
                    carList.add(new Car(Integer.parseInt(split[0]),split[1],split[2],split[3]));
                }

                inputStream.close();

            }
        }
        catch(FileNotFoundException nfe){
            Toast.makeText(context, "cars.txt Dosya Bulunamadı", Toast.LENGTH_SHORT).show();
        }
        catch (IOException io){
            Toast.makeText(context, "car.txt Okuma hatası", Toast.LENGTH_SHORT).show();
        }

        return carList;
    }

    public boolean saveCar(Car car, Context context){
        try{
            OutputStreamWriter outputStreamWriter = new OutputStreamWriter(
                    context.openFileOutput(CAR_FILE_NAME, Context.MODE_APPEND));

            outputStreamWriter.write(String.valueOf(car.getId())+" ");
            outputStreamWriter.write(car.getModel()+" ");
            outputStreamWriter.write(car.getLocationCity()+" ");
            outputStreamWriter.write(car.getType()+" ");
            outputStreamWriter.write(String.valueOf(car.getPrice())+" ");
            outputStreamWriter.write("\n");
            outputStreamWriter.flush();
        }
        catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(context, "Bir hata meydana geldi", Toast.LENGTH_SHORT).show();
            return false;
        }

        return true;
    }

    //verilen userName e ait satırı döndürür
    public String getUser(String userName, Context context){
        String line;
        String [] splitLine;

        try{
            InputStream inputStream = context.openFileInput(USER_FILE_NAME);

            if ( inputStream != null ) {
                InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                while ((line = bufferedReader.readLine()) != null ) {
                    splitLine = line.split(" ");
                    if(splitLine[0].contains(userName))
                        return line; //userName varsa ona ait satır kaydını döndür
                }

                inputStream.close();

            }
        }
        catch(FileNotFoundException nfe){
            Toast.makeText(context, "Dosya Bulunamadı", Toast.LENGTH_SHORT).show();
        }
        catch (IOException io){
            Toast.makeText(context, "Okuma hatası", Toast.LENGTH_SHORT).show();
        }

        return null;
    }

    //verilen satırı parse ederek oluşturduğu user ı döndürür
    public User getUser(String line){
        String []splitLine;
        splitLine = line.split(" ");
        User user = new User();
        user.setUserName(splitLine[0]);
        user.setPassword(splitLine[1]);
        user.setName(splitLine[2]);
        user.setSurname(splitLine[3]);

        return user;
    }

    //dosyaya yeni bir kullanıcıyı kaydeder
    public boolean saveUser(User user, Context context){
        try{
        OutputStreamWriter outputStreamWriter = new OutputStreamWriter(
                context.openFileOutput(USER_FILE_NAME, Context.MODE_APPEND));

            outputStreamWriter.write(user.getUserName()+" ");
            outputStreamWriter.write(user.getPassword()+" ");
            outputStreamWriter.write(user.getName()+" ");
            outputStreamWriter.write(user.getSurname());
            outputStreamWriter.write("\n");
            outputStreamWriter.flush();
        }
        catch (IOException e) {
            e.printStackTrace();
            return false;
        }


        return true;
    }

    //alınmak istenen kullanıcı adının dosyada olup olmadığını kontrol eder
    public boolean isExistUserName(String userName, Context context){
        String line;
        String [] splitLine;

        try{
            InputStream inputStream = context.openFileInput(USER_FILE_NAME);

            if ( inputStream != null ) {
                InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                while ((line = bufferedReader.readLine()) != null ) {
                    splitLine = line.split(" "); //satır boşluk karakterine göre parse edildi
                    if(splitLine[0].equalsIgnoreCase(userName)) //userName dosyadaki ilk sütunda
                        return true; //userName varsa false döndür
                }

                inputStream.close();

            }
        }
        catch(FileNotFoundException nfe){
            Toast.makeText(context, "Dosya Bulunamadı", Toast.LENGTH_LONG).show();
        }
        catch (IOException io){
            Toast.makeText(context, "Okuma hatası", Toast.LENGTH_LONG).show();
        }

        return false;
    }
}
