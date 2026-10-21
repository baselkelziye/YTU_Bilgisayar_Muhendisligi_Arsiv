import React, { useState, useContext, useEffect } from "react";
import { createPortal } from "react-dom";
import Select from 'react-select';
import DatePicker from "react-datepicker";
import "react-datepicker/dist/react-datepicker.css";
import { GoogleMap, Marker, LoadScript } from "@react-google-maps/api";
import style from "./styles.module.css";
import {
    updatePlanApi,
  } from "../api/apiFunctions";
  import TokenContext from "../../contexts/tokenContext";
  import { apiBaseUrl } from '../../config/apiConfig';

const UpdatePopup = ({ onClose, rowData, accessToken, meData, cityList }) => {
  const apiUrl = apiBaseUrl;
  // const { accessToken2, refreshToken } = useContext(TokenContext);
  let accessToken2 = sessionStorage.getItem("accessToken");
  let refreshToken = sessionStorage.getItem("refreshToken");

  // const [employeeUsername, setEmployeeUsername] = useState("");
  const [travelDate, setTravelDate] = useState("");
  const [endLocation, setEndLocation] = useState("");
  const [endCoordinates, setEndCoordinates] = useState("");
  // const [selectedEmployee, setSelectedEmployee] = useState(null);
  const [tempDate, setTempDate] = useState("");
  const [mapPosition, setMapPosition] = useState({ lat: 0, lng: 0 });
  const [selectedCity, setSelectedCity] = useState(null);

  let formattedDate = null;
  
  const handleFormSubmit = async (event) => {
    event.preventDefault();

    const planData = {
      // employeeUsername: employeeUsername,
      travelDate: travelDate,
      endLocation: endLocation,
      accountantUsername: meData.username
    };

    await updatePlanApi(
      accessToken,
      rowData._id,
      planData
    );
  };

  // const options = employeeList
  //   .filter((employee) => employee.role === "employee")
  //   .map((employee) => ({
  //     value: employee.username,
  //     label: `${employee.name} ${employee.surname} (${employee.email})`,
  //   }));

  const handleMapClick = async (event) => {
    // Harita üzerinde tıklanan konumu al
    const clickedLocation = {
      lat: event.latLng.lat(),
      lng: event.latLng.lng(),
    };
    
    try {
      // Google Geocoding API'ye tıklanan konumu sorgula
      const response = await fetch(
        `https://maps.googleapis.com/maps/api/geocode/json?latlng=${clickedLocation.lat},${clickedLocation.lng}&key=api_key`
      );
  
      const data = await response.json();
  
      if (data.results.length > 0) {
        // Geocoding API'den dönen ilk sonucun tam adresini ve koordinatlarını al
        const locationCoordinates = data.results[0].geometry.location;
        const fullAddress = data.results[0].formatted_address;
  
        // SetMapPosition ile harita üzerinde seçilen konumu güncelle
        setMapPosition(locationCoordinates);
  
        // Harita üzerinde seçilen konumu ve tam adresi endLocation ve console.log ile göster
        setEndLocation(fullAddress);
        console.log("endLocation: ", endLocation);
        setEndCoordinates(locationCoordinates);
        console.log("endCoordinates: ", endCoordinates);
      } else {
        console.error('Geocode API returned no results.');
      }
    } catch (error) {
      console.error('Error fetching geocode data:', error);
    }
  };


  const cityOptions = cityList.map((city) => ({
    value: city.city,
    label: city.city,
  }));
  

  useEffect(() => {
    // Update the map position when the selectedCity changes
    if (selectedCity) {
      // Use an API to get the coordinates for the selected city or adjust as needed
      // For the sake of the example, let's assume that you have a function getCoordinatesForCity
      const updateMapPosition = async () => {
        try {
          const locationInfo = await getCoordinatesForCity(selectedCity);
          console.log("Fetched coordinates:", locationInfo);
      
          // Instead of directly setting mapPosition, call setMapPosition here
          setMapPosition(prevPosition => {
            console.log("Setting map position:", locationInfo);
            return locationInfo;
          });
      
        } catch (error) {
          console.error('Error fetching coordinates:', error);
        }
      };
      
  
      updateMapPosition();
    }
  }, [selectedCity]);
  



  const getCoordinatesForCity = async (city) => {
    try {
      const response = await fetch(
        `https://maps.googleapis.com/maps/api/geocode/json?address=${city}&key=api_key`
      );
  
      const data = await response.json();
  
      if (data.results.length > 0) {
        const location = data.results[0].geometry.location;
        const fullAddress = data.results[0].formatted_address;
  
        console.log("harita: ", location);
        console.log("Tam Adres: ", fullAddress);
  
        return { lat: location.lat, lng: location.lng, address: fullAddress };
      } else {
        console.error('Geocode API returned no results.');
        return { lat: 0, lng: 0, address: '' };
      }
    } catch (error) {
      console.error('Error fetching coordinates:', error);
      return { lat: 0, lng: 0, address: '' }; // Default to 0,0 if an error occurs
    }
  };

  return createPortal(
    <div className={style.popupOverlay}>
      <div className={style.popupCard}>
        <form onSubmit={handleFormSubmit}>
          {/* <div className="employeeUsername">
            Employee
            <Select
              className="form-control"
              id="employeeUsername"
              name="employeeUsername"
              value={selectedEmployee}
              // onChange={setSelectedEmployee}
              onChange={(selectedOption) => {
                setSelectedEmployee(selectedOption);
                setEmployeeUsername(selectedOption ? selectedOption.value : "");
              }}
              options={[
                { value: null, label: "Select Employee", isDisabled: true },
                ...options,
              ]}
              isSearchable
            />
          </div> */}
          <div className="travelDate mt-2">
            Travel Date
            <br />
            <DatePicker
              className="form-control"
              selected={tempDate}
              onChange={(date) => (
                setTempDate(date),
                formattedDate = date.toLocaleDateString('tr-TR', {
                  day: 'numeric',
                  month: 'numeric',
                  year: 'numeric'
                }),
                setTravelDate(formattedDate)
                )}
              placeholderText="Select Travel Date"
              dateFormat="dd/MM/yyyy"
            />
          </div>
          <div className="endLocation mt-2">
            Destination
            {selectedCity ? (
              <LoadScript
                googleMapsApiKey="AIzaSyDiA-6dALFcffd3sVMwzPCue0IFk4tB0uw"
                libraries={['places']}
              >
                <GoogleMap
                  mapContainerStyle={{
                    height: "300px",
                    width: "100%",
                  }}
                  center={mapPosition}
                  zoom={15}
                  onClick={handleMapClick}
                >
                  <Marker position={mapPosition} />
                </GoogleMap>
              </LoadScript>
            ) : (
              <Select
                className="form-control"
                id="citySelect"
                name="citySelect"
                value={selectedCity}
                onChange={(selectedOption) => {
                  setSelectedCity(selectedOption ? selectedOption.value : null);
                  setMapPosition({
                    lat: 0,
                    lng: 0,
                  });
                }}
                options={[
                  { value: null, label: "Select City", isDisabled: true },
                  ...cityOptions,
                ]}
                isSearchable
              />
            )}
          </div>
          <br />
          <div className="Update mb-3">
            <button type="submit" className={style.button}>
              Update
            </button>
          </div>
        </form>
        <button className={style.button} onClick={onClose}>
          Close
        </button>
      </div>
    </div>,
    document.getElementById("popup-update")
  );
};

export default UpdatePopup;
