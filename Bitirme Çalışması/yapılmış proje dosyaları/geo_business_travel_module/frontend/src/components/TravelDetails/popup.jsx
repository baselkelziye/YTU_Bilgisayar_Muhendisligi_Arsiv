import React from "react";
import { createPortal } from "react-dom";
import style from "./styles.module.css";

const Popup = ({ message, onClose }) => {
  return createPortal(
    <div className={style.popupOverlay}>
      <div className={style.popupCard}>
        <img
          src={message}
          alt="image"
          style={{ maxWidth: "25rem", maxHeight: "25rem", marginBottom: "1rem" }}
        />
        <button className={style.button} onClick={onClose}>
          Close
        </button>
      </div>
    </div>,
    document.getElementById("popup-root")
  );
};

export default Popup;
