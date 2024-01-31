import "./header.css";

export default function Header() {
  return (
    <div className="header">
      <div className="headerTitles">
        <span className="headerTitleSm"> React & Node </span>
        <span className="headerTitleLg"> BLOG </span>
      </div>
      <img
        className="headerImg"
        src="https://i.ytimg.com/vi/hE2N87kN_4U/maxresdefault.jpg"
        alt=""
      />
    </div>
  );
}