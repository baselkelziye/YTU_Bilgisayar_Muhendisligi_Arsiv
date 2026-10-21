import React, { useContext } from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import { Link, useHistory } from "react-router-dom";
import styles from "./styles.module.css";
// import myImage from "../../images/logo.png";
import myImage from "../../images/icon.png";
import TokenContext from "../../contexts/tokenContext";

function Navbar() {
  const history = useHistory();
  const { updateAccessToken, updateRefreshToken } = useContext(TokenContext);

  const handleLogout = () => {
    sessionStorage.removeItem("accessToken")
    sessionStorage.removeItem("refreshToken")
    updateAccessToken(null);
    updateRefreshToken(null);
    history.push("/login");
  };

  return (
    <>
      <nav className={styles.navbar}>
        <div className="container">
          <div className="row">
            <div className="col-6">
              <ul>
                <li>
                  <img src={myImage} height={"40px"} style={{paddingBottom: "5px"}} />
                </li>
                <li>
                  <Link to="/profile">Profile</Link>
                </li>
                <li>
                  <Link to="/travel">Travels</Link>
                </li>
                <li>
                  <Link to="/plan">Plans</Link>
                </li>
                <li>
                  <Link to="/fee">Taxi Fee</Link>
                </li>
                <li>
                  <Link to="/users">Users</Link>
                </li>
              </ul>
            </div>
            <div className="col-6">
              <ul className="d-flex justify-content-end">
                <li className="ml-auto">
                  <Link to="/login" onClick={handleLogout}>
                    Logout
                  </Link>
                </li>
              </ul>
            </div>
          </div>
        </div>
      </nav>
    </>
  );
}

export default Navbar;
