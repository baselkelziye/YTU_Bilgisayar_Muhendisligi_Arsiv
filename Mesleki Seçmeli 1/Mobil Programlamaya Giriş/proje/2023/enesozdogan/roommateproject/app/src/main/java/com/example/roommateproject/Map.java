package com.example.roommateproject;

import static androidx.core.content.ContextCompat.getSystemService;

import android.content.Context;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;

import com.firebase.geofire.GeoFire;
import com.firebase.geofire.GeoLocation;
import com.firebase.geofire.GeoQuery;
import com.firebase.geofire.GeoQueryEventListener;
import com.google.android.gms.location.LocationRequest;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;

import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.location.FusedLocationProviderClient;
import com.google.android.gms.location.LocationCallback;
import com.google.android.gms.location.LocationResult;
import com.google.android.gms.location.LocationServices;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.HashMap;


public class Map extends Fragment {

    private static final int LOCATION_PERMISSION_REQUEST_CODE = 1;
    EditText radET;
    FirebaseUser currUser;
    DatabaseReference mapDbRef;
    DatabaseReference userDbRef;
    private boolean isFirstLoad = true;
    private GoogleMap googleMap;
    private FusedLocationProviderClient fusedLocationClient;
    private LocationCallback locationCallback;
    private HashMap<String,Marker> markersMap=new HashMap<String,Marker>();
    String userName;

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater,  ViewGroup container,  Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_map, container, false);

        fusedLocationClient = LocationServices.getFusedLocationProviderClient(requireActivity());
        radET=view.findViewById(R.id.radET);
        locationCallback = new LocationCallback() {
            @Override
            public void onLocationResult(LocationResult locationResult) {
                super.onLocationResult(locationResult);
                if (locationResult != null && locationResult.getLastLocation() != null) {
                    Location location = locationResult.getLastLocation();
                    LatLng latLng = new LatLng(location.getLatitude(), location.getLongitude());




                    if(isFirstLoad){
                        SaveToDatabase(location);
                        showAllUserLocations();
                        googleMap.moveCamera(CameraUpdateFactory.newLatLng(latLng));
                        isFirstLoad=false;
                    }

                }
            }
        };

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager().findFragmentById(R.id.mapFragment);
        if (mapFragment != null) {
            mapFragment.getMapAsync(new OnMapReadyCallback() {
                @Override
                public void onMapReady(GoogleMap map) {
                    googleMap = map;
                    if (ActivityCompat.checkSelfPermission(requireContext(), android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED
                            && ActivityCompat.checkSelfPermission(requireContext(), android.Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
                        requestPermissions(new String[]{android.Manifest.permission.ACCESS_FINE_LOCATION, android.Manifest.permission.ACCESS_COARSE_LOCATION}, LOCATION_PERMISSION_REQUEST_CODE);
                    } else {
                        googleMap.setMyLocationEnabled(true);
                        startLocationUpdates();
                    }

                }
            });
        }


        return view;
    }
    private void SaveToDatabase(Location location){

        currUser= FirebaseAuth.getInstance().getCurrentUser();
        mapDbRef = FirebaseDatabase.getInstance().getReference("locations").child(currUser.getUid());
        userDbRef = FirebaseDatabase.getInstance().getReference("Users").child(currUser.getUid());
        userDbRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                User user=snapshot.getValue(User.class);
                userName=user.getUsername();

                HashMap<String, Object> locationData = new HashMap<>();
                locationData.put("latitude", location.getLatitude());
                locationData.put("longitude", location.getLongitude());
                locationData.put("userName", userName);

                mapDbRef.addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot snapshot) {
                        if(snapshot.exists()){
                            mapDbRef.setValue(locationData).addOnSuccessListener(new OnSuccessListener<Void>() {
                                @Override
                                public void onSuccess(Void unused) {
                                    //Toast.makeText(getContext(), "Basariyla Konum eklendi", Toast.LENGTH_SHORT).show();
                                }
                            }).addOnFailureListener(new OnFailureListener() {
                                @Override
                                public void onFailure(@NonNull Exception e) {
                                    Toast.makeText(getContext(), "Konum eklenemedi", Toast.LENGTH_SHORT).show();
                                }
                            });
                        }
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError error) {

                    }
                });
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
      ;



    }
    private void showAllUserLocations() {
        DatabaseReference databaseReference = FirebaseDatabase.getInstance().getReference("locations");
        databaseReference.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                for (DataSnapshot userSnapshot : dataSnapshot.getChildren()) {
                    String userId = userSnapshot.getKey();
                    double latitude = userSnapshot.child("latitude").getValue(Double.class);
                    double longitude = userSnapshot.child("longitude").getValue(Double.class);
                    String username=userSnapshot.child("userName").getValue(String.class);
                    System.out.println("Cekme: "+username);
                    LatLng latLng = new LatLng(latitude, longitude);
                    googleMap.addMarker(new MarkerOptions().position(latLng).title(username));

                    //googleMap.moveCamera(CameraUpdateFactory.newLatLng(latLng));
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {
                Toast.makeText(getContext(), "Konumlar alınamadı", Toast.LENGTH_SHORT).show();
            }
        });
    }
    @Override
    public void onResume() {
        super.onResume();
        startLocationUpdates();
    }

    @Override
    public void onPause() {
        super.onPause();
        stopLocationUpdates();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        stopLocationUpdates();
    }

    private void startLocationUpdates() {
        LocationRequest locationRequest = LocationRequest.create();
        locationRequest.setPriority(LocationRequest.PRIORITY_HIGH_ACCURACY);
        locationRequest.setInterval(5000);
        locationRequest.setFastestInterval(2000);
        if (ActivityCompat.checkSelfPermission(requireContext(), android.Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
                && ActivityCompat.checkSelfPermission(requireContext(), android.Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            fusedLocationClient.requestLocationUpdates(locationRequest, locationCallback, null);
        }
    }
    private void stopLocationUpdates() {
        fusedLocationClient.removeLocationUpdates(locationCallback);
    }

    private void restoreMarkers() {
        // Önceden kaldırılan markerları tekrar ekle
        for (Marker marker : markersMap.values()) {
            marker.setVisible(true);
        }
    }

    // Markerları kaldırma işlemi
    private void clearMarkers() {
        // Tüm markerları kaldır
        for (Marker marker : markersMap.values()) {
            marker.remove();
        }
        // Markerları içeren harita nesnesini temizle
        markersMap.clear();
    }

    // Konumları filtreleyen fonksiyon
    private void filterLocationsByDistance(double centerLatitude, double centerLongitude, double radius) {
        DatabaseReference databaseReference = FirebaseDatabase.getInstance().getReference("locations");

        // Önceki hale döndürme işlemi
        restoreMarkers();

        databaseReference.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {

                // Markerları kaldırma işlemi
                clearMarkers();

                for (DataSnapshot userSnapshot : snapshot.getChildren()) {
                    double userLatitude = userSnapshot.child("latitude").getValue(Double.class);
                    double userLongitude = userSnapshot.child("longitude").getValue(Double.class);
                    String username = userSnapshot.child("username").getValue(String.class);

                    // Konumun merkeze olan uzaklığını hesapla
                    float[] distanceResults = new float[1];

                    Location.distanceBetween(centerLatitude, centerLongitude, userLatitude, userLongitude, distanceResults);
                    float distance = distanceResults[0];

                    if (distance <= radius) {
                        // Yarıçap içindeki konumu işaretle
                        LatLng latLng = new LatLng(userLatitude, userLongitude);
                        MarkerOptions markerOptions = new MarkerOptions()
                                .position(latLng)
                                .title(username);
                        Marker marker = googleMap.addMarker(markerOptions);
                        markersMap.put(userSnapshot.getKey(), marker);
                    }
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                // İstenirse, hata durumunda yapılacak işlemleri burada gerçekleştirebilirsiniz.
            }
        });
    }
}