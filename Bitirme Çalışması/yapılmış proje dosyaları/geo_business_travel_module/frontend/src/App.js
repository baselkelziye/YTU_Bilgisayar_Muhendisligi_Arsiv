import './App.css';
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link,
} from "react-router-dom";
import Login from './components/Login/index';
import Signup from './components/Signup/index';
import Profile from './components/Profile/index';
import Travels from './components/Travels/index';
import { useEffect, useState } from 'react';
import { TokenProvider } from './contexts/tokenContext';
import TravelDetails from './components/TravelDetails';
import { PopupProvider } from './contexts/popupContext';
import TaxiFeeList from './components/TaxiFeeList';
import PlanList from './components/PlanList';
import UserList from './components/UserList';

function App() {
  const [currentPath, setCurrentPath] = useState("/");
  const [click, setClick] = useState(false);
  const [showHome, setShowHome] = useState(true);

  const handleClick = () => {
    setClick(!click);
  };

  useEffect(() => {
    setCurrentPath(window.location.pathname);
  }, [click]);

  useEffect(() => {
    (currentPath === "/" || currentPath === "") ? setShowHome(true) : setShowHome(false);
  }, [currentPath]);

  return (
    <div className="App">
      <TokenProvider>
        <PopupProvider>
          <Router>
            <div>
              {
                showHome &&
                <div>
                  <div className="container" style={{ marginTop: "6rem" }}>
                    {/* <img src='\images\logo.png' alt='logo' width={"100rem"} height={"100rem"} /> */}
                    <div className="row">
                      <h1 style={{ fontSize: "xxx-large" }}>Geo-Business Travel</h1>
                    </div>
                    <div className="row" style={{ marginTop: "10rem" }}>
                      <div className='col-4'/>
                      <div className="col-4">
                        <Link style={{ width: "100%", height: "100%" }} to="/login" onClick={handleClick}><button className="button" style={{ width: "50%", height: "180%" }}>Login</button></Link>
                      </div>
                      <div className='col-4'/>
                      {/* <div className="col-6 d-flex justify-content-start">
                        <Link style={{ width: "100%", height: "100%" }} to="/signup" onClick={handleClick}><button className="button" style={{ width: "50%", height: "180%" }}>Sign Up</button></Link>
                      </div> */}
                    </div>
                  </div>
                </div>
              }

              <Switch>
                <Route exact path="/login">
                  <Login />
                </Route>
                <Route path="/signup">
                  <Signup />
                </Route>
                <Route path="/profile">
                  <Profile />
                </Route>
                <Route path="/travel">
                  <Travels />
                </Route>
                <Route path="/travel-details/:id">
                  <TravelDetails />
                </Route>
                <Route path="/fee">
                  <TaxiFeeList />
                </Route>
                <Route path="/plan">
                  <PlanList />
                </Route>
                <Route path="/users">
                  <UserList />
                </Route>
              </Switch>
            </div>
          </Router>
        </PopupProvider>
      </TokenProvider>
    </div>
  );
}

export default App;
