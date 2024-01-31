import Sidebar from "../../components/sidebar/Sidebar"
import "./settings.css"

export default function Settings() {
	return (
		<div className="settings">
			<div className="settingsWrapper">
				<div className="settingsTitle">
					<span className="settingsUpdateTitle">Update Your Account</span>
					<span className="settingsDeleteTitle">Delete Account</span>

				</div>
				<form className="settingsForm">
					<label> Profile Picture</label>
					<div className="settingsPP">
						<img src="https://static.toiimg.com/thumb/resizemode-4,msid-76729536,width-1200,height-900/76729536.jpg" alt=""/>
						<label htmlFor="fileInput">
						<i className="settingsPPIcon far fa-user-circle"></i>
						</label>

						<input type="file" id="fileInput" style={{display: "none"}} />
					
					</div>

					<label >Username</label>
					<input type="text" placeholder="Group G"/>
					<label>Email</label>
					<input type="email" placeholder="GroupG@gmail.com" />
					<label >Password</label>
					<input type="password" palceholder="****"/>
					<button className="settingsSubmit">Update</button>
				</form>
					
			</div>
			<Sidebar/>
		
		</div>
	)
}
