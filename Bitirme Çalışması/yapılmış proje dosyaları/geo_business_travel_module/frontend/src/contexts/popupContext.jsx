import { createContext, useState, useContext } from "react";

const PopupContext = createContext();

export const PopupProvider = ({ children }) => {
  const [loginErrorMessage, setLoginErrorMessage] = useState("");
  const [showLoginPopup, setShowLoginPopup] = useState(false);
  const [signupErrorMessage, setSignupErrorMessage] = useState("");
  const [showSignupPopup, setShowSignupPopup] = useState(false);
  const [invoicePhoto, setInvoicePhoto] = useState("");
  const [showInvoicePhotoPopup, setshowInvoicePhotoPopup] = useState(false);

  const updateLoginErrorMessage = (newLoginErrorMessage) => {
    setLoginErrorMessage(newLoginErrorMessage);
  };
  const updateShowLoginPopup = (newShowLoginPopup) => {
    setShowLoginPopup(newShowLoginPopup);
  };
  const updateSignupErrorMessage = (newSignupErrorMessage) => {
    setSignupErrorMessage(newSignupErrorMessage);
  };
  const updateShowSignupPopup = (newShowSignupPopup) => {
    setShowSignupPopup(newShowSignupPopup);
  };
  const updateInvoicePhoto = (newInvoicePhoto) => {
    setInvoicePhoto(newInvoicePhoto);
  };
  const updateShowInvoicePhotoPopup = (newShowInvoicePhotoPopup) => {
    setshowInvoicePhotoPopup(newShowInvoicePhotoPopup);
  };
  
  return (
    <PopupContext.Provider
      value={{
        loginErrorMessage,
        updateLoginErrorMessage,
        showLoginPopup,
        updateShowLoginPopup,
        signupErrorMessage,
        updateSignupErrorMessage,
        showSignupPopup,
        updateShowSignupPopup,
        invoicePhoto,
        updateInvoicePhoto,
        showInvoicePhotoPopup,
        updateShowInvoicePhotoPopup
      }}
    >
      {children}
    </PopupContext.Provider>
  );
};

export default PopupContext;

export const usePopupContext = () => {
  return useContext(PopupContext);
};
