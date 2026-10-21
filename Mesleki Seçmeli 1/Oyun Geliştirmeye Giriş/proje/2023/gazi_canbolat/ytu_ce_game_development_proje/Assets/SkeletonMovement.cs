using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
public class SkeletonMovement : MonoBehaviour
{
    public GameObject go;
    public NavMeshAgent agent;
    public Sensor sensor;
    public ThirdPersonMovement playerSc;
    private Animator anim;
    public bool isStopped;
    public GameObject LoseScreen;
    // Start is called before the first frame update
    void Start()
    {
        sensor = GetComponent<Sensor>();
        playerSc = go.GetComponent<ThirdPersonMovement>();
        anim = gameObject.GetComponent<Animator>();
        isStopped = false;
        LoseScreen = playerSc.LoseScreen;
    }

    // Update is called once per frame
    void Update()
    {       
        if(anim.GetBool("IsAttacking")&&anim.GetCurrentAnimatorStateInfo(0).normalizedTime > 0.9f&& !anim.IsInTransition(0)){
                anim.SetBool("IsAttacking", false);
            }
        if(sensor.isSeeing){
            playerSc.adrenaline = true;
            agent.SetDestination(go.transform.position);
            if(agent.remainingDistance>agent.stoppingDistance)
                anim.SetBool("IsWalking", true);
            else{
                anim.SetBool("IsWalking", false);
                if(Vector3.Distance(transform.position, go.transform.position)<agent.stoppingDistance)
                    anim.SetBool("IsAttacking", true);
            }
            
            if(sensor.isInCloseArea && anim.GetBool("IsAttacking")&&anim.GetCurrentAnimatorStateInfo(0).normalizedTime > 0.4f&& !anim.IsInTransition(0)){
                StartCoroutine(die());
            }
                
        }else if(sensor.isInMidArea && playerSc.isRunning){
            agent.SetDestination(go.transform.position);
            if(agent.remainingDistance>agent.stoppingDistance)
                anim.SetBool("IsWalking", true);
            else{
                anim.SetBool("IsWalking", false);
            }
        }else{
            if(agent.remainingDistance>agent.stoppingDistance)
                anim.SetBool("IsWalking", true);
            else{
                anim.SetBool("IsWalking", false);
            }
            playerSc.adrenaline = false;
        }
    }
    IEnumerator die()
    {
        go.SetActive(false);
        yield return new WaitForSeconds(1);
        LoseScreen.SetActive(true);
        Cursor.visible = true;
         Cursor.lockState = CursorLockMode.None;
    }
}
