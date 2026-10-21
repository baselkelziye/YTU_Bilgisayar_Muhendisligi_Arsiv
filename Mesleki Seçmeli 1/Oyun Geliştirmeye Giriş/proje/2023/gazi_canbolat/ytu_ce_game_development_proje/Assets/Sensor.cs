using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sensor : MonoBehaviour
{
    public float Area;
    [Range(0, 360)]
    public float Radius;
    //[HideInInspector]
    public List<Transform> VisibleTargets = new List<Transform>();


    [Range(0, 1)]
    public float MidArea,CloseArea;

    public LayerMask ObjectsToDetect;
    public LayerMask Obstacles;

    public bool isSeeing,isInFarArea,isInMidArea,isInCloseArea;

    public GameObject VisibleObject,PerceivedObject;
 
    public Collider[] ObjectsInArea;
    private void Update()
    {
        SensorFunc();
    }

    private void SensorFunc()
    {
        VisibleTargets.Clear();
        ObjectsInArea = Physics.OverlapSphere(transform.position, Area, ObjectsToDetect);

        for (int i = 0; i < ObjectsInArea.Length; i++)
        {
            Transform Target = ObjectsInArea[i].transform;
            Vector3 DirectTarget = (Target.position - transform.position).normalized;
            if (Vector3.Angle(transform.forward, DirectTarget) < Radius / 2)
            {
                float DistanceTarget = Vector3.Distance(transform.position, Target.position);

                if (!Physics.Raycast(transform.position, DirectTarget, DistanceTarget, Obstacles))
                {
                    VisibleTargets.Add(Target);

                    float DeltaDistance2 = Mathf.Infinity;
                    foreach (Transform FoundObjects in VisibleTargets)
                    {
                        Vector3 ConflictArea = FoundObjects.transform.position - transform.position;
                        float Distance = ConflictArea.sqrMagnitude;
                        if (Distance < DeltaDistance2)
                        {
                            VisibleObject = FoundObjects.gameObject;
                            DeltaDistance2 = Distance;

                            isSeeing = true;
                        }
                    }
                }
            }
        }






        float DeltaDistance = Mathf.Infinity;
        foreach (Collider FoundObjects in ObjectsInArea)
        {
            Vector3 ConflictArea = FoundObjects.transform.position - transform.position;
            float Distance = ConflictArea.sqrMagnitude;
            float TargetsDistance;
            if (Distance < DeltaDistance)
            {
                PerceivedObject = FoundObjects.gameObject;
                DeltaDistance = Distance;

                TargetsDistance = Vector3.Distance(gameObject.transform.position, PerceivedObject.transform.position);
                if(TargetsDistance < Area){
                    isInFarArea = true;
                }
                else{
                    isInFarArea = false;
                }
                if (TargetsDistance < Area * MidArea)
                {
                    isInMidArea = true;
                }
                else
                {
                    isInMidArea = false;
                }

                if (TargetsDistance < Area * (MidArea * CloseArea))
                {
                    isInCloseArea = true;
                }
                else
                {
                    isInCloseArea = false;
                }
            }
        }



        if (!isSeeing)
        {
            VisibleObject = null;
        }
        if (ObjectsInArea.Length == 0)
        {
            PerceivedObject = null;
        }
        if (VisibleTargets.Count == 0)
        {
            isSeeing = false;
        }
    }

    private void OnDrawGizmos()
    {

        if (isSeeing)
        {
            Gizmos.color = Color.red;
        }
        else if(isInFarArea)
        {
            Gizmos.color = Color.cyan;
        }
        else
        {
            Gizmos.color = Color.white;
        }
        Gizmos.DrawWireSphere(transform.position, Area);

        if (isInMidArea)
        {
            Gizmos.color = Color.red;
        }
        else
        {
            Gizmos.color = Color.blue;
        }
        Gizmos.DrawWireSphere(transform.position, Area * (MidArea));

        if (isInCloseArea)
        {
            Gizmos.color = Color.red;
        }
        else
        {
            Gizmos.color = Color.yellow;
        }

        Gizmos.DrawWireSphere(transform.position, Area * (MidArea * CloseArea));

        Gizmos.color = Color.white;
        Gizmos.DrawWireSphere(transform.position, Area);
        Vector3 gorus_acisi_1 = Derece_Acisi(-Radius / 2, false);
        Vector3 gorus_acisi_2 = Derece_Acisi(Radius / 2, false);

        Gizmos.color = Color.yellow;
        Gizmos.DrawLine(transform.position, transform.position + gorus_acisi_1 * Area);
        Gizmos.DrawLine(transform.position, transform.position + gorus_acisi_2 * Area);

        Gizmos.color = Color.green;
        foreach (Transform VisibleTarget in VisibleTargets)
        {
            Gizmos.DrawLine(transform.position, VisibleTarget.position);
        }

        Gizmos.color = Color.red;
        if (VisibleObject != null)
        {
            Gizmos.DrawLine(transform.position, VisibleObject.transform.position);
        }

    }

    public Vector3 Derece_Acisi(float angleInDegrees, bool angleIsGlobal)
    {
        if (!angleIsGlobal)
        {
            angleInDegrees += transform.eulerAngles.y;
        }
        return new Vector3(Mathf.Sin(angleInDegrees * Mathf.Deg2Rad), 0, Mathf.Cos(angleInDegrees * Mathf.Deg2Rad));
    }
}
