
    do {
        printf("choose 1- enqueue, 2- dequeue, 3-print, 4-exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                printf("enter the value to push: ");
                scanf("%d", &val);
                insertAtBeginning(&head,val);
                traverse(head);
                break;
            }
            case 2: {
                deleteAtHead(&head);
                traverse(head);
                break;
            }
            case 3: {
                traverse(head);
                break;
            }
            case 4: {
                break;
            }
            default: {
                printf("wrong choice\n");
            }
        }
    } while (n != 4);

    return;
}

