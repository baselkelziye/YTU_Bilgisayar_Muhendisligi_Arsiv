import React, { useState, useContext } from "react";
import style from "./styles.module.css";
import { signupApi } from "../api/apiFunctions";
import TokenContext from "../../contexts/tokenContext";
import PopupContext from "../../contexts/popupContext";
import { useHistory } from "react-router-dom";

function Form() {
  const [username, setUsername] = useState("");
  const [name, setName] = useState("");
  const [surname, setSurname] = useState("");
  const [email, setEmail] = useState("");
  const [role, setRole] = useState("");
  // const role = "accountant";
  const [password, setPassword] = useState("");
  const [password2, setPassword2] = useState("");
  const history = useHistory();
  const { updateAccessToken, updateRefreshToken } = useContext(TokenContext);
  const { updateSignupErrorMessage, updateShowSignupPopup } =
    useContext(PopupContext);

  // function isValidEmail(email) {
  //   const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  //   return emailRegex.test(email);
  // }

  const handleFormSubmit = async (event) => {
    event.preventDefault();
    if (
      username === "" ||
      name === "" ||
      surname === "" ||
      email === "" ||
      password === "" ||
      password2 === ""
    ) {
      updateSignupErrorMessage("Form entries cannot be empty!");
      updateShowSignupPopup(true);
    }
    // else if (isValidEmail(email)) {
    //   updateSignupErrorMessage("Invalid e-mail!");
    //   updateShowSignupPopup(true);
    // }
    else if (username.length < 5) {
      updateSignupErrorMessage("Username cannot be less than 5 characters!");
      updateShowSignupPopup(true);
    } else if (password.length < 8) {
      updateSignupErrorMessage("Password cannot be less than 8 characters!");
      updateShowSignupPopup(true);
    } else if (password !== password2) {
      updateSignupErrorMessage("Passwords entered do not match!");
      updateShowSignupPopup(true);
    } else {
      const result = await signupApi(
        username,
        name,
        surname,
        email,
        password,
        role
      );
      if (result.error) {
        updateSignupErrorMessage(
          "This email and/or username is already in use!"
        );
        updateShowSignupPopup(true);
      } else {
        updateAccessToken(result.accessToken);
        updateRefreshToken(result.refreshToken);
        history.push("/profile");
      }
    }
  };

  return (
    <>
      <form onSubmit={handleFormSubmit}>
        <div className="name">
          <label htmlFor="name">Name:</label>
          <input
            class="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="text"
            id="name"
            name="name"
            onChange={(e) => setName(e.target.value)}
          />
        </div>
        <div className="surname mt-2">
          <label htmlFor="surname">Surname:</label>
          <input
            class="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="text"
            id="surname"
            name="surname"
            onChange={(e) => setSurname(e.target.value)}
          />
        </div>
        <div className="email mt-2">
          <label htmlFor="email">E-mail:</label>
          <input
            class="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="email"
            id="email"
            name="email"
            onChange={(e) => setEmail(e.target.value)}
          />
        </div>
        <div className="username mt-2">
          <label htmlFor="username">Username:</label>
          <input
            class="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="text"
            id="username"
            name="username"
            onChange={(e) => setUsername(e.target.value)}
          />
        </div>
        <div className="role mt-2">
          <label htmlFor="role">Role:</label>
          <select
            className="form-control"
            id="role"
            name="role"
            onChange={(e) => setRole(e.target.value)}
            value={role}
          >
            <option value="" disabled></option>
            <option value="employee">employee</option>
            {/* <option value="admin">Admin</option> */}
            <option value="accountant">accountant</option>
            {/* Add more roles as needed */}
          </select>
          {/* <input
            class="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="text"
            id="role"
            name="role"
            onChange={(e) => setRole(e.target.value)}
          /> */}
        </div>
        <div className="password mt-2">
          <label htmlFor="password">Password:</label>
          <input
            class="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="password"
            id="password"
            name="password"
            onChange={(e) => setPassword(e.target.value)}
          />
        </div>
        <div className="password2 mt-2">
          <label htmlFor="password2">Re-enter Password:</label>
          <input
            class="form-control"
            aria-label="Large"
            aria-describedby="inputGroup-sizing-sm"
            type="password"
            id="password2"
            name="password2"
            onChange={(e) => setPassword2(e.target.value)}
          />
        </div>
        <div className="login mt-4">
          <button
            type="submit"
            className={style.button}
            style={{ backgroundColor: "#F4D03F" }}
          >
            Ok
          </button>
        </div>
      </form>
    </>
  );
}

export default Form;
