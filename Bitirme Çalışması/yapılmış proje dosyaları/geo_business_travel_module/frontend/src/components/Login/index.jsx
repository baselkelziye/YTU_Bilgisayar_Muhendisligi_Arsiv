import React, { Fragment, useContext } from "react";
import { Link } from "react-router-dom";
import "bootstrap/dist/css/bootstrap.min.css";
import Form from "./form";
import style from "./styles.module.css";
import PopupContext from "../../contexts/popupContext";
import Popup from "./popup";

function Login() {
  const { updateLoginErrorMessage, updateShowLoginPopup, loginErrorMessage } =
    useContext(PopupContext);

  const closePopup = () => {
    updateShowLoginPopup(false);
    updateLoginErrorMessage("");
  };

  return (
    <Fragment>
      <div className="container mt-3 mb-3">
        <div className="row d-flex justify-content-between">
          <div className="login-card d-flex flex-column align-items-center mt-5">
            <div
              className="card mt-5 pt-5"
              style={{ backgroundColor: "#F4D03F", border: "none" }}
            >
              <div className="p-5">
                <h2
                  className="mb-4"
                  style={{ color: "#333", fontSize: "xx-large" }}
                >
                  Login
                </h2>
                <Form />
                <br />
                {/* <div className="sign-up-div">
                  <Link to="/signup">
                    <button className={style.button}>Sign Up</button>
                  </Link>
                </div> */}
              </div>
              <div id="popup-root"></div>
              {loginErrorMessage && (
                <Popup
                  message={loginErrorMessage}
                  onClose={closePopup}
                  style={style.popupStyle}
                />
              )}
            </div>
          </div>
        </div>
      </div>
    </Fragment>
  );
}

export default Login;
