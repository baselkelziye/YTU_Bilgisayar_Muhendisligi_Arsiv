import React, { Fragment, useContext } from "react";
import { useParams } from "react-router-dom";
import { travelDetailsApi, usersApi } from "../api/apiFunctions";
import TokenContext from "../../contexts/tokenContext";
import useSWR from "swr";
import { DataTable } from "primereact/datatable";
import { Column } from "primereact/column";
import Navbar from "../Navbar/index";
import style from "./styles.module.css";
import PopupContext from "../../contexts/popupContext";
import Popup from "./popup";
import { apiBaseUrl } from '../../config/apiConfig';

function TravelDetails() {
  const { id } = useParams();
  const travelId = id;
  const apiUrl = apiBaseUrl;
  // const { accessToken, refreshToken } = useContext(TokenContext);
  let accessToken = sessionStorage.getItem("accessToken");
  let refreshToken = sessionStorage.getItem("refreshToken");
  const {
    invoicePhoto,
    updateInvoicePhoto,
    showInvoicePhotoPopup,
    updateShowInvoicePhotoPopup,
  } = useContext(PopupContext);

  const { data: userList, isLoading: userListIsLoading } = useSWR(
    `${apiUrl}/auth/users`,
    async (url) => {
      const response = await usersApi(accessToken, refreshToken, "POST");
      return response;
    }
  );

  const findUserByName = (username) => {
    const user = userList.find((user) => user.username === username);
    return user ? `${user.name} ${user.surname} (${user.email} - ${user.username})` : "";
  };

  const { data, isLoading } = useSWR(
    `${apiUrl}/travel/${travelId}`,
    async (url) => {
      const response = await travelDetailsApi(accessToken, travelId, "GET");
      return response;
    }
  );
  const dataArray = [data];

  function handleInvoicePhotoPopup(rowData) {
    updateInvoicePhoto(rowData.invoicePhoto);
    updateShowInvoicePhotoPopup(true);
  }

  const closePopup = () => {
    updateShowInvoicePhotoPopup(false);
    updateInvoicePhoto("");
  };

  const renderSuspiciousCell = (rowData) => {
    const cellStyle = {
      color: rowData.suspicious === "yes" ? "red" : "green",
    };

    return <span style={cellStyle}>{rowData.suspicious}</span>;
  };

  const renderImageCell = (rowData) => {
    const handleImageClick = () => {
      handleInvoicePhotoPopup(rowData);
    };
    return (
      <img
        src={rowData.invoicePhoto}
        //src={`http://192.168.1.54:4000/upload/1705415706102.jpg`}
        alt="Invoice"
        style={{ maxWidth: "100px", cursor: "pointer" }}
        onClick={handleImageClick}
      />
    );
  };

  const renderStatusCell = (rowData) => {
    let cellStyle = { color: "black" };
    if (rowData.status === "approved") {
      cellStyle = { color: "green" };
    }
    if (rowData.status === "rejected") {
      cellStyle = { color: "red" };
    }
    return <span style={cellStyle}>{rowData.status}</span>;
  };

  return (
    <Fragment>
      <Navbar />
      <div className="container mt-3 mb-3">
        <div className="row d-flex justify-content-between">
          <div className="login-card d-flex flex-column align-items-center">
            <div className="card">
              <h2 className="pt-3">Travel Details: </h2>
              {!isLoading && !userListIsLoading && (
                <DataTable value={dataArray} tableStyle={{ minWidth: "50rem" }}>
                  <Column
                    className={style.customColumn}
                    field="employeeUsername"
                    header="Employee"
                    body={(rowData) => findUserByName(rowData.employeeUsername)}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="travelDate"
                    header="Travel Date"
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="startLocation"
                    header="Start Location"
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="endLocation"
                    header="End Location"
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="invoicePhoto"
                    header="Invoice Photo"
                    body={renderImageCell}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="invoiceInfo"
                    header="Travel Distance (Km)"
                  ></Column>
                  {/* <Column
                    className={style.customColumn}
                    field="invoiceNote"
                    header="Invoice Note"
                  ></Column> */}
                  <Column
                    className={style.customColumn}
                    field="invoicePrice"
                    header="Invoice Price  (TL)"
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="priceEstimate"
                    header="Price Estimate  (TL)"
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="suspicious"
                    header="Suspicious"
                    body={renderSuspiciousCell}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="status"
                    header="Status"
                    body={renderStatusCell}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="approveByAccountant"
                    header="Approve/Reject By Accountant"
                    body={(rowData) =>
                      findUserByName(rowData.approveByAccountant)
                    }
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="approveDate"
                    header="Approve/Reject Date"
                  ></Column>
                </DataTable>
              )}
            </div>
          </div>
        </div>
      </div>
      <div id="popup-root"></div>
      {showInvoicePhotoPopup && (
        <Popup
          message={invoicePhoto}
          onClose={closePopup}
          style={style.popupStyle}
        />
      )}
    </Fragment>
  );
}

export default TravelDetails;
