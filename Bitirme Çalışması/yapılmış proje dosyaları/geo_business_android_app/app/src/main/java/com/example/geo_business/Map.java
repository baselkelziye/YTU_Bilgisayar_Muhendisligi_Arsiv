package com.example.geo_business;


import static com.example.config.ApiConfig.BASE_API_URL;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.drawable.Drawable;
import android.location.Location;
import android.media.Image;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.telecom.Call;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.core.content.FileProvider;


import com.example.adapters.TravelAdapter;
import com.example.api_requests.CityApiRequest;
import com.example.api_requests.CreateTravelApiRequest;
import com.example.api_requests.TravelsApiRequest;
import com.example.config.ApiConfig;
import com.example.models.Travel;
import com.example.models.User;
import com.example.shared_data.TokenData;
import com.example.shared_data.UserData;
import com.google.android.gms.location.FusedLocationProviderClient;
import com.google.android.gms.location.LocationServices;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptor;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.Circle;
import com.google.android.gms.maps.model.CircleOptions;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.android.gms.maps.model.PolylineOptions;
import com.google.android.gms.maps.model.Polyline;
import com.google.android.gms.location.LocationCallback;
import com.google.android.gms.location.LocationRequest;
import com.google.android.gms.location.LocationResult;
import com.google.gson.Gson;
import com.googlecode.tesseract.android.TessBaseAPI;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import okhttp3.Callback;
import okhttp3.MultipartBody;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;
import okhttp3.MediaType;

import com.example.config.ApiConfig;


public class Map extends AppCompatActivity implements OnMapReadyCallback {
    private LocationRequest locationRequest;
    private LocationCallback locationCallback;
    Circle destinationCircle;
    private static final int MAP_PERMISSION_CODE = 101;
    public static final int CAMERA_PERM_CODE = 102;
    public static final int CAMERA_REQUEST_CODE = 103;
    private static final String TAG = "MapActivity";
    FusedLocationProviderClient fusedLocationProviderClient;
    GoogleMap map;
    double userLat, userLong, curLat, curLong;
    private LatLng destinationLocation, userLocation, currentLocation;
    Button startButton, endButton, okButton, retakeButton;
    TextView info;
    private boolean isTravelStarted;
    static String currentPhotoPath;
    static String currentPhotoName;
    static String currentCity;
    static String startLocation;
    static String endLocation;
    static String photoLink;
    static String travelDistance;
    static Float invoicePrice;
    static Float priceEstimate;


    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_map);

        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map);
        if (mapFragment != null) {
            mapFragment.getMapAsync(this);
        }

        fusedLocationProviderClient = LocationServices.getFusedLocationProviderClient(this);

        // Lokasyon talebi (request) ve callback
        locationRequest = new LocationRequest();
        locationRequest.setInterval(5000); // Lokasyonu her 5 saniyede bir güncelle
        locationRequest.setFastestInterval(5000);
        locationRequest.setPriority(LocationRequest.PRIORITY_HIGH_ACCURACY);

        locationCallback = new LocationCallback() {
            @Override
            public void onLocationResult(LocationResult locationResult) {
                if (locationResult != null) {
                    Location location = locationResult.getLastLocation();
                    if (location != null) {
                        // Güncellenmiş lokasyon
                        updateCurrentLocation(location);
                    }
                }
            }
        };

        startButton = (Button) findViewById(R.id.startButton);
        endButton = (Button) findViewById(R.id.endButton);
        okButton = (Button) findViewById(R.id.okButton);
        retakeButton = (Button) findViewById(R.id.retakeButton);
        info = (TextView) findViewById(R.id.info);

        endButton.setVisibility(View.INVISIBLE);
        info.setVisibility(View.INVISIBLE);
        okButton.setVisibility(View.INVISIBLE);
        retakeButton.setVisibility(View.INVISIBLE);

        startButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                isTravelStarted = true;
                startButton.setVisibility(View.INVISIBLE);
                endButton.setVisibility(View.VISIBLE);
                info.setVisibility(View.VISIBLE);
            }
        });

        endButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //  Kullanıcı hedef lokasyonda mı
                Boolean inside =  isUserInsideCircle(currentLocation, destinationLocation, 100);

                if (inside) {
                    // Kullanıcı dairenin içinde
                    Toast.makeText(Map.this, "Take a invoice photo", Toast.LENGTH_SHORT).show();
                    isTravelStarted = false;
                    endButton.setVisibility(View.INVISIBLE);
                    okButton.setVisibility(View.VISIBLE);
                    retakeButton.setVisibility(View.VISIBLE);
                    endButton.setVisibility(View.INVISIBLE);
                    startButton.setVisibility(View.INVISIBLE);
                    verifyCameraPermisson();
                } else {
                    // Kullanıcı dairenin dışında
                    Toast.makeText(Map.this, "You are not in the target position", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        startLocationUpdates();
    }

    @Override
    protected void onPause() {
        super.onPause();
        stopLocationUpdates();
    }

    private void startLocationUpdates() {
        if (ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
                && ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            fusedLocationProviderClient.requestLocationUpdates(locationRequest, locationCallback, null);
        }
    }

    private void stopLocationUpdates() {
        fusedLocationProviderClient.removeLocationUpdates(locationCallback);
    }

    // Güncellenmiş lokasyonu işleme
    private void updateCurrentLocation(Location location) {
        curLat = location.getLatitude();
        curLong = location.getLongitude();

        currentLocation = new LatLng(curLat, curLong);
    }

    @Override
    public void onMapReady(@NonNull GoogleMap googleMap) {
        map = googleMap;

        if (ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            // İzin yoksa izin talebi yap
            ActivityCompat.requestPermissions(this, new String[]{android.Manifest.permission.ACCESS_FINE_LOCATION, android.Manifest.permission.ACCESS_COARSE_LOCATION}, MAP_PERMISSION_CODE);
            return;
        }
        map.setMyLocationEnabled(true);
        map.getUiSettings().setZoomControlsEnabled(true);

        map.setOnMapClickListener(new GoogleMap.OnMapClickListener() {
            @Override
            public void onMapClick(@NonNull LatLng latLng) {
                if(!isTravelStarted) {
                    map.clear();
                    destinationLocation = latLng;
                    Log.d("destinationLocation", destinationLocation.toString());
                    MarkerOptions markerOptions = new MarkerOptions();
                    markerOptions.position(latLng);
                    markerOptions.icon(setIcon(Map.this, R.drawable.lock_black_24dp));
                    map.addMarker(markerOptions);

                    getRoute(userLocation, destinationLocation);

                    // 100 metre yarıçaplı bir daire çiz
                    drawDestinationCircle(destinationLocation, 100);
                }
            }
        });

        fetchMyLocation();
    }

    private void getRoute(LatLng origin, LatLng destination) {
        String apiKey = "api_key";
        String url = "https://maps.googleapis.com/maps/api/directions/json?origin=" +
                origin.latitude + "," + origin.longitude +
                "&destination=" + destination.latitude + "," + destination.longitude +
                "&mode=driving&key=" + apiKey;

        new FetchDirectionsTask().execute(url);
    }

    private void drawDestinationCircle(LatLng center, double radius) {
        if (destinationCircle != null) {
            destinationCircle.remove(); // Daha önce çizilmiş bir daire varsa kaldır
        }

        CircleOptions circleOptions = new CircleOptions()
                .center(center)
                .radius(radius)
                .strokeColor(Color.BLUE)
                .strokeWidth(2)
                .fillColor(Color.argb(70, 0, 0, 255));

        destinationCircle = map.addCircle(circleOptions);
    }

    private boolean isUserInsideCircle(LatLng currentLocation, LatLng circleCenter, double circleRadius) {
        float[] distance = new float[1];

        // Haversine formülü ile iki konum arasındaki mesafeyi hesapla
        Location.distanceBetween(
                currentLocation.latitude, currentLocation.longitude,
                circleCenter.latitude, circleCenter.longitude,
                distance
        );

        // Hesaplanan mesafeyi dairenin yarıçapı ile karşılaştır
        return distance[0] <= circleRadius;
    }


    private class FetchDirectionsTask extends AsyncTask<String, Void, String> {
        @Override
        protected String doInBackground(String... params) {
            try {
                URL url = new URL(params[0]);
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();

                InputStream inputStream = connection.getInputStream();
                BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
                StringBuilder result = new StringBuilder();
                String line;

                while ((line = reader.readLine()) != null) {
                    result.append(line);
                }

                return result.toString();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return null;
        }

        @Override
        protected void onPostExecute(String result) {
            // JSON yanıtını çözümle
            JSONObject jsonResponse = null;
            try {
                jsonResponse = new JSONObject(result);
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }

            // "routes" dizisinden ilk rota al
            JSONArray routesArray = null;
            try {
                routesArray = jsonResponse.getJSONArray("routes");
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }
            JSONObject firstRoute = null;
            try {
                firstRoute = routesArray.getJSONObject(0);
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }

            // İlk rota içinden "legs" dizisinden ilk bacak al
            JSONArray legsArray = null;
            try {
                legsArray = firstRoute.getJSONArray("legs");
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }
            JSONObject firstLeg = null;
            try {
                firstLeg = legsArray.getJSONObject(0);
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }

            // Başlangıç noktasını içeren "start_address" alanını al
            String startAddress = null;
            try {
                startAddress = firstLeg.getString("start_address");
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }

            String endAddress = null;
            try {
                endAddress = firstLeg.getString("end_address");
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }

            String city = extractCity(startAddress);
            currentCity = city;
            startLocation = startAddress;
            endLocation = endAddress;

            // İlk bacak içinden "distance" alanını al
            JSONObject distanceObject = null;
            try {
                distanceObject = firstLeg.getJSONObject("distance");
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }

            // "text" alanından mesafe metnini al
            String distanceText = null;
            try {
                distanceText = distanceObject.getString("text");
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }

            // Toast mesajını oluştur ve göster
            String toastMessage = "Distance: " + distanceText;
            Toast.makeText(Map.this, toastMessage, Toast.LENGTH_SHORT).show();
            info.setText("Distance: " + distanceText);

            // Sayısal değeri çıkarmak için regex
            String regex = "[0-9]+\\.*[0-9]*";
            Pattern pattern = Pattern.compile(regex);
            Matcher matcher = pattern.matcher(distanceText);

            // Eşleşen değeri bulma
            if (matcher.find()) {
                String matchedValue = matcher.group();
                System.out.println("Distance: " + matchedValue);

                // km-m dönüştür
                if(distanceText.contains("km")) {
                    System.out.println("ok");;
                }
                else {
                    matchedValue = String.valueOf(Float.valueOf(matchedValue) / 100.0F);
                }

                Toast.makeText(Map.this, matchedValue+" Km", Toast.LENGTH_SHORT).show();

                travelDistance = matchedValue;
            }

            // Harita üzerinde çizgi çiz
            drawPolylineOnMap(result);
        }
    }

    private static String extractCity(String address) {
        //Pattern pattern = Pattern.compile("(\\w+/\\w+),");
        //Pattern pattern = Pattern.compile("\\b(\\p{L}+)/\\p{L}+\\b");
        Pattern pattern = Pattern.compile("(\\p{L}+)/(\\p{L}+),.*");
        Matcher matcher = pattern.matcher(address);

        if (matcher.find()) {
            // Eşleşen kısımları alarak şehir ve ilçe/ülke bilgisini çıkar
            String cityPart = matcher.group(2);

            return cityPart.trim();
        }

        return null; // Eşleşme bulunamazsa null döndürülebilir
    }

    private void drawPolylineOnMap(String result) {
        try {
            JSONObject json = new JSONObject(result);

            JSONArray routes = json.getJSONArray("routes");

            JSONObject route = routes.length() > 0 ? routes.getJSONObject(0) : null;
            if (route != null) {
                JSONObject overviewPolyline = route.getJSONObject("overview_polyline");
                String encodedPolyline = overviewPolyline.getString("points");

                List<LatLng> polylineList = decodePoly(encodedPolyline);

                PolylineOptions polylineOptions = new PolylineOptions()
                        .addAll(polylineList)
                        .width(10)
                        .color(Color.BLUE);

                Polyline polyline = map.addPolyline(polylineOptions);
            }

        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    private List<LatLng> decodePoly(String encoded) {
        List<LatLng> poly = new ArrayList<>();
        int index = 0, len = encoded.length();
        int lat = 0, lng = 0;

        while (index < len) {
            int b, shift = 0, result = 0;
            do {
                b = encoded.charAt(index++) - 63;
                result |= (b & 0x1f) << shift;
                shift += 5;
            } while (b >= 0x20);
            int dlat = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));
            lat += dlat;

            shift = 0;
            result = 0;
            do {
                b = encoded.charAt(index++) - 63;
                result |= (b & 0x1f) << shift;
                shift += 5;
            } while (b >= 0x20);
            int dlng = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));
            lng += dlng;

            double latDouble = lat / 1e5;
            double lngDouble = lng / 1e5;
            poly.add(new LatLng(latDouble, lngDouble));
        }

        return poly;
    }

    private void fetchMyLocation() {
        if (ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            return;
        }
        Task<Location> task = fusedLocationProviderClient.getLastLocation();

        task.addOnSuccessListener(new OnSuccessListener<Location>() {
            @Override
            public void onSuccess(Location location) {
                userLat = location.getLatitude();
                userLong = location.getLongitude();

                userLocation = new LatLng(userLat, userLong);

                LatLng latLng = new LatLng(userLat, userLong);

                CameraPosition cameraPosition = new CameraPosition.Builder().target(latLng).zoom(14).build();

                map.animateCamera(CameraUpdateFactory.newCameraPosition(cameraPosition));
                map.addMarker(new MarkerOptions().position(latLng)
                        .icon(setIcon(Map.this, R.drawable.baseline_register_circle_24)));

            }
        });
    }

    public void verifyCameraPermisson() {
        String[] permissions = {
                android.Manifest.permission.READ_EXTERNAL_STORAGE,
                android.Manifest.permission.WRITE_EXTERNAL_STORAGE,
                android.Manifest.permission.CAMERA
        };

        if(ContextCompat.checkSelfPermission(this.getApplicationContext(), permissions[0]) == PackageManager.PERMISSION_GRANTED
                && ContextCompat.checkSelfPermission(this.getApplicationContext(), permissions[1]) == PackageManager.PERMISSION_GRANTED
                && ContextCompat.checkSelfPermission(this.getApplicationContext(), permissions[2]) == PackageManager.PERMISSION_GRANTED) {
            dispatchTakePictureIntent();
        }
        else {
            ActivityCompat.requestPermissions(this, permissions, CAMERA_PERM_CODE);
        }

    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if(requestCode == CAMERA_PERM_CODE) {
            if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                dispatchTakePictureIntent();
                // Image captured successfully, now start OCR
            }else {
                Toast.makeText(this, "Permission is required to use the camera!", Toast.LENGTH_SHORT).show();
            }
        }
    }

    private void dispatchTakePictureIntent() {
        Intent takePictureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        File photoFile = null;
        if (takePictureIntent.resolveActivity(getPackageManager()) != null) {
            photoFile = null;

            try {
                photoFile = createImageFile();
            } catch (IOException exception) {
                Toast.makeText(this, "Photo file could not be created!", Toast.LENGTH_SHORT).show();
            }

            if (photoFile != null) {
                Uri photoUri = FileProvider.getUriForFile(this, "com.example.geo_business", photoFile);
                takePictureIntent.putExtra(MediaStore.EXTRA_OUTPUT, photoUri);
                startActivityForResult(takePictureIntent, CAMERA_REQUEST_CODE);
            }
        }

    }

    private File createImageFile() throws IOException {
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String imageFileName = "Geo_Business_" + timeStamp + "_";
        File storageDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        File image = File.createTempFile(imageFileName, ".jpg", storageDir);

        currentPhotoPath = image.getAbsolutePath();
        currentPhotoName = imageFileName;

        return image;
    }

    // startActivityForResult sonucunu dinleyen metod
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == CAMERA_REQUEST_CODE && resultCode == RESULT_OK) {
            // Image captured successfully, start OCR
            startOCR();
        }
    }

    private void startOCR() {
        // Copy the traineddata file from assets to internal storage
        copyTessData();

        // Initialize Tesseract API
        TessBaseAPI tessBaseAPI = new TessBaseAPI();
        tessBaseAPI.init(getFilesDir().getPath(), "tur");

        // Set the image for OCR processing

        BitmapFactory.Options options = new BitmapFactory.Options();

        int maxWidth = 1920; // Maksimum genişlik değeri
        int maxHeight = 1080; // Maksimum yükseklik değeri

        // Resmin boyutunu al
        int originalWidth = options.outWidth;
        int originalHeight = options.outHeight;

        // Ölçek faktörünü belirle
        int inSampleSize = 1;
        if (originalWidth > maxWidth || originalHeight > maxHeight) {
            final int halfWidth = originalWidth / 2;
            final int halfHeight = originalHeight / 2;

            while ((halfWidth / inSampleSize) > maxWidth && (halfHeight / inSampleSize) > maxHeight) {
                inSampleSize *= 2;
            }
        }

        // options.inSampleSize = inSampleSize;
        options.inJustDecodeBounds = false;

        Bitmap bitmap = null;
        bitmap = BitmapFactory.decodeFile(currentPhotoPath, options);

        // tessBaseAPI.setImage(bitmap);
        tessBaseAPI.setImage(rotateBitmap(bitmap, 90));

        // Get the recognized text
        String recognizedText = tessBaseAPI.getUTF8Text();

        // process the recognized text
        if (!TextUtils.isEmpty(recognizedText)) {
            // Fatura fiyatını tespit etmek için regex
            String regex = "(?i)(?:Tutar|Top|Toplam)\\s*(?::|)\\s*[*]*\\s*([\\d,.]+)";
            Pattern pattern = Pattern.compile(regex);
            Matcher matcher = pattern.matcher(recognizedText);

            // Eşleşen değerleri bulma
            while (matcher.find()) {
                String matchedValue = matcher.group(1); // Grup 1, sayısal değeri içerir
                invoicePrice = Float.valueOf(matchedValue);
            }

            getCity();
            saveImageToServer(new File(currentPhotoPath));
        } else {
            Toast.makeText(this, "OCR failed. No text recognized.", Toast.LENGTH_SHORT).show();
        }

        // End the OCR processing
        tessBaseAPI.end();
    }

    // Bitmap'ı x açı döndürme
    private Bitmap rotateBitmap(Bitmap source, float angle) {
        Matrix matrix = new Matrix();
        matrix.postRotate(angle);
        return Bitmap.createBitmap(source, 0, 0, source.getWidth(), source.getHeight(), matrix, true);
    }

    private void copyTessData() {
        try {
            String path = getFilesDir().getPath() + "/tessdata/";
            String filePath = path + "tur.traineddata";

            File dir = new File(path);
            if (!dir.exists()) {
                if (!dir.mkdirs()) {
                    return;
                }
            }
            else {
                Log.d("ocr", "tur için dosya var");
            }

            InputStream inputStream = getAssets().open("tessdata/tur.traineddata");
            FileOutputStream outputStream = new FileOutputStream(filePath);

            byte[] buffer = new byte[1024];
            int read;
            while ((read = inputStream.read(buffer)) != -1) {
                outputStream.write(buffer, 0, read);
            }

            inputStream.close();
            outputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void getCity() {
        String[] tokens = TokenData.getInstance().getSharedData();
        String accessToken = tokens[0];

        // API request
        String apiUrl = ApiConfig.BASE_API_URL + "/fee/" + currentCity;
        CityApiRequest cityApiRequest = new CityApiRequest(new CityApiRequest.ApiCallback() {
            @Override
            public void onTaskComplete(String result) {
                try {
                    // Transform JSON response to JSON Array
                    JSONObject jsonResponse = new JSONObject(result);

                    if (jsonResponse.has("error")) {
                        // Login error
                        Toast.makeText(Map.this, "Error!", Toast.LENGTH_SHORT).show();
                    } else {
                        // Login successfully
                        String city = jsonResponse.getString("city");
                        String openingFee = jsonResponse.getString("openingFee");
                        String feePerKm = jsonResponse.getString("feePerKm");
                        String shortDistance = jsonResponse.getString("shortDistance");

                        priceEstimate = Float.valueOf(openingFee) + Float.valueOf(travelDistance) * Float.valueOf(feePerKm);

                        if(priceEstimate < Float.valueOf(shortDistance)) {
                            priceEstimate = Float.valueOf(shortDistance);
                        }

                    }

                } catch (JSONException e) {
                    e.printStackTrace();
                    Log.e(TAG, "JSON Parsing Error: " + e.getMessage());
                    Toast.makeText(Map.this, "ERROR!", Toast.LENGTH_SHORT).show();
                }
            }
        });

        cityApiRequest.execute(apiUrl, "GET", currentCity, accessToken);
    }

    private void saveImageToServer(File file) {
        OkHttpClient client = new OkHttpClient();
        RequestBody requestBody = new MultipartBody.Builder()
                .setType(MultipartBody.FORM)
                .addFormDataPart("photo", currentPhotoName+".jpg",
                        RequestBody.create(MediaType.parse("image/*"), file))
                .build();

        Request request = new Request.Builder()
                .url(BASE_API_URL+"/upload")
                .post(requestBody)
                .build();
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onResponse(@NonNull okhttp3.Call call, @NonNull Response response) throws IOException {
                if (response.isSuccessful()) {
                    String responseData = response.body().string();

                    // Assuming `responseData` contains the JSON response
                    try {
                        JSONObject json = new JSONObject(responseData);
                        photoLink = json.getString("fileLink");

                        setTravelData();
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }

            }

            @Override
            public void onFailure(@NonNull okhttp3.Call call, @NonNull IOException e) {
                e.printStackTrace();
            }

        });
    }

    public void setTravelData() {

        User user = UserData.getInstance().getSharedData();
        String employeeUsername = user.getUsername();

        // Bugünün tarihini al
        LocalDate today = LocalDate.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM/dd/yyyy");
        String travelDate = today.format(formatter);

        String suspicious = "yes";

        if((invoicePrice != null) && (priceEstimate != null)) {
            if (invoicePrice > priceEstimate * 1.25) {
                suspicious = "yes";
            }
            else {
                suspicious = "no";
            }
        }

        String invoicePhoto = photoLink;
        String invoiceInfo = travelDistance;

        String status = "waiting";
        String approveByAccountant = "-";
        String approveDate = "-";

        Travel travel = new Travel(
                employeeUsername, travelDate.toString(), startLocation, endLocation, invoicePhoto, invoiceInfo+" km",
                "note", invoicePrice, priceEstimate, suspicious, status, approveByAccountant, approveDate
        );

        Gson gson = new Gson();
        String body =  gson.toJson(travel);

        String[] tokens = TokenData.getInstance().getSharedData();
        String accessToken = tokens[0];

        // API request
        String apiUrl = ApiConfig.BASE_API_URL + "/travel/";

        CreateTravelApiRequest createTravelApiRequest = new CreateTravelApiRequest(new CreateTravelApiRequest.ApiCallback() {
            @Override
            public void onTaskComplete(String result) {

                if(result == null) {
                    Toast.makeText(Map.this, "The save operation failed!", Toast.LENGTH_SHORT).show();
                    dispatchTakePictureIntent();
                }

                Intent intent = new Intent(getApplicationContext(), Menu.class);
                startActivity(intent);

            }
        });

        if (invoicePrice == null) {
            dispatchTakePictureIntent();
        }

        info.setVisibility(View.VISIBLE);
        info.setText("Invoice Price: " + String.valueOf(invoicePrice) + " TL");

        retakeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dispatchTakePictureIntent();
            }
        });

        okButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                createTravelApiRequest.execute(apiUrl, body, accessToken);
            }
        });

    }

    private BitmapDescriptor setIcon(Activity activity, int drawableId) {
        Drawable drawable = ActivityCompat.getDrawable(activity, drawableId);
        drawable.setBounds(0, 0, drawable.getIntrinsicWidth(), drawable.getIntrinsicHeight());
        Bitmap bitmap = Bitmap.createBitmap(drawable.getIntrinsicWidth(), drawable.getIntrinsicHeight(), Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(bitmap);
        drawable.draw(canvas);
        return BitmapDescriptorFactory.fromBitmap(bitmap);
    }

}
