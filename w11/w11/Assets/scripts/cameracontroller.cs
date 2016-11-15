using UnityEngine;
using System.Collections;

public class cameracontroller : MonoBehaviour {

	public GameObject player;
	private Vector3 offset;
	// Use this for initialization
	void Start () {
		offset = transform.position - player.transform.position;
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	//For follow camera,procedural animations,etc.,it's best to use dateUpdate
	//lateUpdate,runs after all items have been processed

	void LateUpdate() {
		transform.position = player.transform.position + offset;

	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.CompareTag ("Pike Up")) {
			other.gameObject.SetActive (false);
		}
	}
}
