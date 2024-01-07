import "./write.css"

export default function Write() {
	return (
		<div className="write">
			<img src="https://pbs.twimg.com/media/EkDJ5TlXYAIH6aw.jpg" alt="" 
			className="writeImg" />
			<form className="writeForm">
			<div className="writeFormGroup">
				<label htmlFor="fileInput">
				<i className="writeIcon fas fa-plus"></i>
				</label>
				<input type="file" id="fileInput" style={{display:"none"}} />
				<input type="text" placeholder="Title" className="writeInput" autoFocus={true} />	
			</div>
			<div className="writeFormGroup">
				<textarea placeholder="Yazmaya Basla... " type="text" className="writeInput writeText"></textarea>
			</div>
			<button className="writeSubmit"> Publish </button>
			</form>
		</div>
	)
}
