import "./post.css"

export default function Post() {
	return (
		<div className="post">
			<img className="postImg" src="https://i01.sozcucdn.com/wp-content/uploads/2021/06/17/iecrop/10milletbahcesi_16_9_1623971561.jpg" alt="" />
			<div className="postInfo">
				<div className="postCats">
					<span className="postCat">Music</span>
					<span className="postCat">Life</span>
				</div>
				<span className="postTitle">
					Lorem ipsum dolor sit amet consectetur adipisicing elit.
				</span>
				<hr />
				<span className="postDate">1 hour ago</span>
			</div>
			<p className="postDesc">
				Lorem, ipsum dolor sit amet consectetur adipisicing elit. Soluta aspernatur saepe aperiam, corporis ad voluptatum cupiditate esse dignissimos sit. Velit quod quaerat accusantium quidem odit placeat labore ipsam sapiente dolorem?
			</p>

			<div className="comments">
				

			</div>
		</div>
	)
}
