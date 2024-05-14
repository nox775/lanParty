Queue *createQueue();
void enQueue(Queue *, teamInfo);

int isEmptyQueue(Queue *);

teamInfo deQueue(Queue *);
void deleteQueue(Queue *);

void QueueExtractFromList(Queue **, Node *);
void QueueExtractFromStack(Queue **, Node *);