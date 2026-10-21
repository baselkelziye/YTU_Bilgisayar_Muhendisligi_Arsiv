import React, { useState, useContext } from "react";
import style from "./styles.module.css";
import { loginApi } from "../api/apiFunctions";
import TokenContext from "../../contexts/tokenContext";
import PopupContext from "../../contexts/popupContext";
import { useHistory } from "react-router-dom";

function Form() {
  const history = useHistory();
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const { updateAccessToken, updateRefreshToken } = useContext(TokenContext);
  const { updateLoginErrorMessage, updateShowLoginPopup } =
    useContext(PopupContext);

  const handleFormSubmit = async (event) => {
    event.preventDefault();
    const result = await loginApi(username, password);
    if (result.error) {
      updateLoginErrorMessage("Username or password incorrect!");
      updateShowLoginPopup(true);
    } else if (result && result.user.role !== "employee") {
      sessionStorage.setItem("accessToken", result.accessToken);
      sessionStorage.setItem("refreshToken", result.refreshToken);
      updateAccessToken(result.accessToken);
      updateRefreshToken(result.refreshToken);
      history.push("/profile");
    } else {
      updateLoginErrorMessage(
        "Employees cannot log in to the accounting system!"
      );
      updateShowLoginPopup(true);
    }
  };

  return (
    <>
      <form onSubmit={handleFormSubmit}>
        <div className="username">
          <input
            className="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="text"
            id="username"
            name="username"
            placeholder="Username"
            value={username}
            onChange={(e) => setUsername(e.target.value)}
          />
        </div>
        <div className="password mt-2">
          <input
            type="password"
            className="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm  type="
            id="password"
            name="password"
            placeholder="Password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
          />
        </div>
        <br />
        <div className="login">
          <button type="submit" className={style.button}>
            Login
          </button>
        </div>
      </form>
    </>
  );
}

export default Form;
