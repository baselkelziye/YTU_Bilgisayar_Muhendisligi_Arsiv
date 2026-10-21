import { createContext, useState, useContext } from "react";

const TokenContext = createContext();

export const TokenProvider = ({ children }) => {
  const [accessToken, setAccessToken] = useState("");
  const [refreshToken, setRefreshToken] = useState("");

  const updateAccessToken = (newAccessToken) => {
    setAccessToken(newAccessToken);
  };
  const updateRefreshToken = (newRefreshToken) => {
    setRefreshToken(newRefreshToken);
  };
  
  return (
    <TokenContext.Provider
      value={{
        accessToken,
        updateAccessToken,
        refreshToken,
        updateRefreshToken,
      }}
    >
      {children}
    </TokenContext.Provider>
  );
};

export default TokenContext;

export const useTokenContext = () => {
  return useContext(TokenContext);
};
