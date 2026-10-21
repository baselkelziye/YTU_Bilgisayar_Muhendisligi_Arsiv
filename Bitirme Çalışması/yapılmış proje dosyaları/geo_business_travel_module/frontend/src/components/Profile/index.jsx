import React, { Fragment, useContext } from "react";
import TokenContext from "../../contexts/tokenContext";
import { profileApi } from "../api/apiFunctions";
import useSWR from "swr";
import Navbar from "../Navbar/index";
import style from "./styles.module.css";
import { apiBaseUrl } from '../../config/apiConfig';

function Profile() {
  // const { accessToken, refreshToken } = useContext(TokenContext);
  const apiUrl = apiBaseUrl;

  let accessToken = sessionStorage.getItem("accessToken");
  let refreshToken = sessionStorage.getItem("refreshToken");

  console.log("accessToken: ", accessToken)

  const { data, isLoading } = useSWR(`${apiUrl}/auth/me`, async (url) => {
    const response = await profileApi(accessToken, refreshToken, "POST");
    return response;
  });

  return (
    <Fragment>
      <Navbar />
      <div className="container mt-3 mb-3">
        <div className="row d-flex justify-content-between">
          <div className="login-card d-flex flex-column align-items-center">
            <div
              className="card mt-5 pt-2"
              style={{ backgroundColor: "#F4D03F", border: "none" }}
            >
              <h2 className="mb-5">Profile</h2>
              {!isLoading && (
                <div className={style.profileContainer}>
                  <div className={style.profileItem}>
                    <strong>_id:</strong>
                    <span>{data._id}</span>
                  </div>
                  <div className={style.profileItem}>
                    <strong>Username:</strong>
                    <span>{data.username}</span>
                  </div>
                  <div className={style.profileItem}>
                    <strong>Name:</strong>
                    <span>{data.name}</span>
                  </div>
                  <div className={style.profileItem}>
                    <strong>Surname:</strong>
                    <span>{data.surname}</span>
                  </div>
                  <div className={style.profileItem}>
                    <strong>Email:</strong>
                    <span>{data.email}</span>
                  </div>
                  <div className={style.profileItem}>
                    <strong>Role:</strong>
                    <span>{data.role}</span>
                  </div>
                </div>
              )}
            </div>
          </div>
        </div>
      </div>
    </Fragment>
  );
}

export default Profile;
