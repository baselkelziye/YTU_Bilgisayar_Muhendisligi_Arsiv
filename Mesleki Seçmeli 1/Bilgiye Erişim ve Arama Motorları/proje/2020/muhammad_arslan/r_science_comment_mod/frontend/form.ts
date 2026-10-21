const commentBox = document.getElementById('comment') as HTMLTextAreaElement
const modelKey = document.getElementById('model-key') as HTMLSelectElement
const submitBtn = document.getElementById('submit-btn') as HTMLInputElement


if (commentBox && modelKey && submitBtn) {
  console.log("Success")

  commentBox.addEventListener('input', _ => {
    if (commentBox.checkValidity()) {
      submitBtn.removeAttribute('disabled')
      console.log('Is valid now')
    }
  })

  commentBox.addEventListener('invalid', _ => {
    submitBtn.setAttribute('disabled', 'true')
  })
} else
  console.log("Required form elements not found")
