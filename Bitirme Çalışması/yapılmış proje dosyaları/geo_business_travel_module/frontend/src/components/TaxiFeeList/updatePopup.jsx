import React, { useState } from "react";
import { createPortal } from "react-dom";
import style from "./styles.module.css";
import {
    updateCityApi,
  } from "../api/apiFunctions";

const UpdatePopup = ({ onClose, rowData, accessToken }) => {
  const [openingFee, setOpeningFee] = useState(0);
  const [feePerKm, setFeePerKm] = useState(0);
  const [shortDistance, setShortDistance] = useState(0);
  
  const handleFormSubmit = async (event) => {
    event.preventDefault();
    await updateCityApi(
      accessToken,
      rowData.city,
      openingFee,
      feePerKm,
      shortDistance
    );
  };

  return createPortal(
    <div className={style.popupOverlay}>
      <div className={style.popupCard}>
        <form onSubmit={handleFormSubmit}>
          <div className="openingFee">
            Opening Fee
            <input
              className="form-control"
              aria-label="Large"
              aria-describedby="inputGroup-sizing-sm"
              type="text"
              id="openingFee"
              name="openingFee"
              placeholder="Opening Fee"
              value={openingFee}
              onChange={(e) => setOpeningFee(e.target.value)}
            />
          </div>
          <div className="FeePerKm mt-2">
            Fee/Km
            <input
              className="form-control"
              aria-label="Large"
              aria-describedby="inputGroup-sizing-sm  type="
              id="FeePerKm"
              name="FeePerKm"
              placeholder="Fee/Km"
              value={feePerKm}
              onChange={(e) => setFeePerKm(e.target.value)}
            />
          </div>
          <div className=" mt-2">
            Short Distance
            <input
              className="form-control"
              aria-label="Large"
              aria-describedby="inputGroup-sizing-sm  type="
              id="shortDistance"
              name="shortDistance"
              placeholder="Short Distance"
              value={shortDistance}
              onChange={(e) => setShortDistance(e.target.value)}
            />
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