Node* findPredecessor(Node* root, Node* p) {
    // add your logic here
	Node*pred = 0 ;
	Node*curr = root;
	while(curr){
		if(curr->data < p->data){
			pred = curr ;
			curr = curr->right;
		}
		else{
			curr = curr->left;
		}
	}
	return pred;
}


//work@tech