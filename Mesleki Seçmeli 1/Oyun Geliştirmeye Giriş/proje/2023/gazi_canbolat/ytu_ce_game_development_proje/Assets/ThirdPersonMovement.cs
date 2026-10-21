using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class ThirdPersonMovement : MonoBehaviour
{   
    public float range = 5;
    public Transform cam;
    public CharacterController controller;
    public float speed = 6f;
    public float turnSmoothTime = 0.1f;
    public float turnSmoothVelocity;
    public bool isRunning = true, adrenaline = false;
    private Animator anim;
    public LayerMask Enemies;
    public GameObject adrenalineHud;
    public GameObject GateObject;
    public GameObject WinScreen;
    public GameObject LoseScreen;
    public GameObject[] skeletons;
    public Key key;
    public int sceneID;
    private bool gameOn = true;
    void Start(){
       anim = gameObject.GetComponent<Animator>();
       key = GetComponent<Key>();
       sceneID = SceneManager.GetActiveScene().buildIndex;
       skeletons = GameObject.FindGameObjectsWithTag("Enemy");
    }
    void Update()
    {   
        if(Vector3.Distance(transform.position, GateObject.transform.position)<2.5f && key.key){
            if(sceneID<SceneManager.sceneCountInBuildSettings-1)
                SceneManager.LoadScene(sceneID + 1);
            else{
                WinScreen.SetActive(true);
                Cursor.visible = true;
                 Cursor.lockState = CursorLockMode.None;
                 gameOn = false;
        }
        }else if(gameOn){
        skeletons = GameObject.FindGameObjectsWithTag("Enemy");
        foreach(GameObject skeleton in skeletons){
            Sensor sensor = skeleton.GetComponent<Sensor>();
            if(sensor.isSeeing){
                adrenaline = true;
            }
        }
        adrenalineHud.SetActive(adrenaline);
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        Vector3 direction = new Vector3(horizontal, 0f, vertical).normalized;
        if(direction.magnitude >= 0.1f){
            float targetAngle = Mathf.Atan2(direction.x, direction.z)*Mathf.Rad2Deg+cam.eulerAngles.y;
            float angle = Mathf.SmoothDampAngle(transform.eulerAngles.y, targetAngle, ref turnSmoothVelocity, turnSmoothTime);
            
            //Vector3 moveDir = Quaternion.Euler(0f, targetAngle, 0f)*Vector3.forward;
            
            if(!anim.GetBool("IsStabbing")){
                transform.rotation = Quaternion.Euler(0f, angle, 0f);
            }
            //controller.Move(moveDir*speed*Time.deltaTime);
        }

        Collider[] hitColliders = Physics.OverlapSphere(transform.position, range, Enemies);
            if(hitColliders.Length!=0){
                var target = hitColliders[0].transform.position - transform.position;
                 target.y = 0;
                var rot = Quaternion.LookRotation(target); 
                transform.rotation = Quaternion.Slerp(transform.rotation, rot, turnSmoothTime);
            }

        Cursor.lockState = CursorLockMode.Locked;
        Move();
        if(anim.GetBool("IsStabbing")&&anim.GetCurrentAnimatorStateInfo(0).normalizedTime > 0.9f&& !anim.IsInTransition(0)){
            anim.SetBool("IsStabbing", false);
            skeletons = GameObject.FindGameObjectsWithTag("Enemy");
            foreach(GameObject skeleton in skeletons){
                if(skeleton.GetComponent<Sensor>().isInCloseArea){
                    Destroy(skeleton);
                    if(skeletons.Length!=1)
                        key.isKeyDropped();
                    else 
                        key.DropKey();
                }
            }
        }
        
        Stab();
        if(Input.GetKeyUp(KeyCode.C)){
            isRunning = !isRunning;
            }
        if(adrenaline)
            isRunning = true;
        anim.SetBool("IsRunning", isRunning);
    }
    }
    void Move(){
        anim.SetBool("IsMoving", false);
        if(Input.GetKey(KeyCode.W)||Input.GetKey(KeyCode.S)||Input.GetKey(KeyCode.A)||Input.GetKey(KeyCode.D)){
            anim.SetBool("IsMoving", true);
        }
    }
    bool checkForStab(){
        skeletons = GameObject.FindGameObjectsWithTag("Enemy");
        foreach(GameObject skeleton in skeletons){
            if(skeleton.GetComponent<Sensor>().isInCloseArea){
                return true;
            }
        }
        return false;
    }
    void Stab(){
        if(Input.GetKeyUp(KeyCode.E) && !adrenaline && checkForStab()){
            anim.SetBool("IsStabbing", true);
        }
    }
    /* void OnTriggerEnter(Collider col)
    {   Debug.Log(col.gameObject.layer == LayerMask.NameToLayer("Enemy"));
        if (col.gameObject.layer == LayerMask.NameToLayer("Enemy") && col.gameObject.GetComponent<Animator>().GetBool("IsAttacking")) {
            Destroy(this.gameObject);
            LoseScreen.SetActive(true);
        }
    } */
}
