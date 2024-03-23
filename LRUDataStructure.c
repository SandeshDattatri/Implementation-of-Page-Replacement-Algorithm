class LRUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.cacheMap = new Map();
        this.cacheList = [];
    }

    get(page) {
        if (this.cacheMap.has(page)) {
            const index = this.cacheList.indexOf(page);
            if (index !== -1) {
                this.cacheList.splice(index, 1);
                this.cacheList.unshift(page);
            }
            return true; // Page found in cache
        }
        return false; // Page not found in cache
    }

    put(page) {
        if (this.cacheMap.has(page)) {
            // Update existing page
            this.get(page);
        } else {
            if (this.cacheList.length === this.capacity) {
                const leastRecentlyUsed = this.cacheList.pop();
                this.cacheMap.delete(leastRecentlyUsed);
            }
            this.cacheMap.set(page, true);
        }
        this.cacheList.unshift(page);
    }
}
