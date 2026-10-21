import React, { Fragment, useContext } from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import Form from "./form";
import style from "./styles.module.css";
import PopupContext from "../../contexts/popupContext";
import Popup from "./popup";
import { Link } from "react-router-dom";

function Signup() {
  const {
    updateSignupErrorMessage,
    updateShowSignupPopup,
    signupErrorMessage,
  } = useContext(PopupContext);

  let accessToken = sessionStorage.getItem("accessToken");
  let refreshToken = sessionStorage.getItem("refreshToken");

  const closePopup = () => {
    updateShowSignupPopup(false);
    updateSignupErrorMessage("");
  };

  return (
    <Fragment>
      <div className="container mt-3 mb-3">
        <div className="row d-flex justify-content-between">
          {!signupErrorMessage && (
            <div className="login-card d-flex flex-column align-items-center">
              <div className="card mt-2" style={{ borderColor: "#333" }}>
                <div className="p-5">
                  <h2 className="mb-4">Sign Up</h2>
                  <Form />
                  <br />
                  <div className="login">
                    <Link to="/profile">
                      <button
                        className={style.button}
                        style={{ backgroundColor: "#F4D03F" }}
                      >
                        Geri
                      </button>
                    </Link>
                  </div>
                </div>
              </div>
            </div>
          )}
          <div id="popup-root"></div>
          {signupErrorMessage && (
            <Popup
              message={signupErrorMessage}
              onClose={closePopup}
              style={style.popupStyle}
            />
          )}
        </div>
      </div>
    </Fragment>
  );
}

export default Signup;
