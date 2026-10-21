import React, { Fragment, useContext, useState } from "react";
import { DataTable } from "primereact/datatable";
import { Column } from "primereact/column";
import {
    createPlanApi,
    getPlansListApi,
    updatePlanApi,
    deletePlanApi,
    profileApi,
    usersApi,
    citiesApi
  } from "../api/apiFunctions";
import useSWR, { mutate } from "swr";
import TokenContext from "../../contexts/tokenContext";
import Navbar from "../Navbar/index";
import style from "./styles.module.css";
import { Button } from "bootstrap";
import { apiBaseUrl } from '../../config/apiConfig';
import { useHistory } from "react-router-dom";

function TaxiFeeList() {
  const [currentPage, setCurrentPage] = useState(1);
  const apiUrl = apiBaseUrl;
  //const { accessToken, refreshToken } = useContext(TokenContext);
  let accessToken = sessionStorage.getItem("accessToken");
  let refreshToken = sessionStorage.getItem("refreshToken");

  const history = useHistory();

  const { data: userList, isLoading: userIsLoading } = useSWR(
    `${apiUrl}/auth/users`,
    async (url) => {
      const response = await usersApi(accessToken, refreshToken, "POST");
      return response;
    }
  );

  const onPageChange = (event) => {
    setCurrentPage(event.first / event.rows + 1);
  };

  const handleCreate = async () => {
    history.push("/signup");
  };

  return (
    <Fragment>
      <Navbar />
      <div className="container mt-3 mb-3">
        <div className="row d-flex justify-content-between">
          <div className="login-card d-flex flex-column align-items-center">
            <div className="pb-3">
              <button
                className={style.button}
                style={{ color: "green", marginLeft: "250%" }}
                onClick={() => handleCreate()}
              >
              Create
              </button>
            </div>
            <div className="card">
              <h2 className="pt-3">User List</h2>
              {/* {!isLoading && !userListIsLoading && !accountantIsLoading && ( */}
              {(
                <DataTable
                  className={style.customDatatable}
                  value={userList}
                  tableStyle={{ minWidth: "50rem", maxWidth: "100%" }}
                //   rowClassName={rowClassName}
                  onPageChange={onPageChange}
                  paginator={true}
                  rows={5}
                  totalRecords={userList ? userList.length : 0}
                  filterDisplay={(!userIsLoading) ? "row" : false}
                  scrollable={(!userIsLoading) ? "vertical" : false}
                  scrollHeight={(!userIsLoading) ? "500px" : false}
                >
                  <Column
                    className={style.customColumn}
                    field="username"
                    header="Username"
                    filter
                    filterField="username"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="name"
                    header="Name"
                    filter
                    filterField="name"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="surname"
                    header="Surname"
                    filter
                    filterField="surname"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="email"
                    header="Email"
                    filter
                    filterField="email"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="role"
                    header="Role"
                    filter
                    filterField="role"
                    showFilterMenu={false}
                  ></Column>
                </DataTable>
              )}
            </div>
          </div>
        </div>
      </div>
    </Fragment>
  )
};

export default TaxiFeeList;
