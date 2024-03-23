class FIFOQueue {
    constructor(capacity) {
        this.capacity = capacity;
        this.queue = [];
    }

    isFull() {
        return this.queue.length === this.capacity;
    }

    isEmpty() {
        return this.queue.length === 0;
    }

    enqueue(page) {
        if (!this.isFull()) {
            this.queue.push(page);
        }
    }

    dequeue() {
        if (!this.isEmpty()) {
            return this.queue.shift();
        }
        return null;
    }

    contains(page) {
        return this.queue.includes(page);
    }

    getQueue() {
        return this.queue;
    }
}
