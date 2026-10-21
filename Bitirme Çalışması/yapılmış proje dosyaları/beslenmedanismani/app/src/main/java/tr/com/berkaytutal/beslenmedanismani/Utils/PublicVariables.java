package tr.com.berkaytutal.beslenmedanismani.Utils;

/**
 * Created by berka on 15.05.2017.
 */

public interface PublicVariables {


    int TYPE_LISTINGS_ALL = 1;
    int TYPE_LISTINGS_HOMEPAGE  = 2;

    String videoBaseURL = "http://bitirmeprojesi.azurewebsites.net/videos/";

    String CARDIO = "Cardio";

    int ALL_ID = 0;




    int FILTER_BUTTON_TYPE_PROGRAM = 1;
    int FILTER_BUTTON_TYPE_USER = 2;


    int homepageListingCount = 3;



    String addMoneyURL= "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/loadMoney/";


    String insertBodyRatioURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/insertUserBodyRates/";

    String programDiffURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/getProgramDiffParameters";
    String programCategoriesURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/getProgramSpecParameters";
    String allProgramsURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/getAllPrograms/";
    String allUsersURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/getAllTrainers/";
    String getTrainerDetailsURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/getTrainerDetails/";
    String loginURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/loginUser";
    String registerURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/addNewUser";
    String userUpdateURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/updateUserSimpleData";
    String bodyRateUpdateURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/updateUserBodyRates";
    String reportURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/sendComplain";
    String commentURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/voting";
    String getCommentsURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/getAllComments/";
    //getProgramDetailsURL + programID/userID
    String getProgramDetailsURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/getProgramDetails/";

    String searchFilterURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/searchFilter";


    String buyProgramURL = "http://denememustafa.azurewebsites.net/bitirmewebservice/webapi/myresource/buyProgram";


}
