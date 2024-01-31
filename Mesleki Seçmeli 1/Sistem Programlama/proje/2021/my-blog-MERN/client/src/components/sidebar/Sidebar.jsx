import "./sidebar.css"

export default function Sidebar() {
	return (
		<div className="sidebar">
			<div className="sidebarItem">
				<span className="sidebarTitle">ABOUT YTU</span>
				<img src="https://upload.wikimedia.org/wikipedia/commons/3/37/Y%C4%B1ld%C4%B1z_Technical_University_Logo.png" alt="" />
				<p>
					Lorem ipsum dolor sit amet consectetur adipisicing elit. Fugiat sed aliquid totam dolorum reiciendis assumenda, consequatur dolor sunt eveniet 
				</p>
			
			</div>
			<div className="sidebarItem">
				<span className="sidebarTitle">CATEGORIES</span>
				<ul className="sidebarList">
					<li className="sidebarListItem">Life</li>
					<li className="sidebarListItem">Music</li>
					<li className="sidebarListItem">Style</li>
					<li className="sidebarListItem">Sport</li>
					<li className="sidebarListItem">Tech</li>
					<li className="sidebarListItem">Cinema</li>
				</ul>
			</div>
			<div className="sidebarItem">
				<span className="sidebarTitle">FOLLOW US</span>
				<div className="sidebarSocial">
				<i className="sidebar Icon fab fa-facebook-square"></i>
				<i className="sidebar Icon fab fa-twitter-square"></i>
				<i className="sidebar Icon fab fa-pinterest-square"></i>
				<i className="sidebar Icon fab fa-instagram-square"></i>
				</div>
			</div>
		</div>
	)
}
