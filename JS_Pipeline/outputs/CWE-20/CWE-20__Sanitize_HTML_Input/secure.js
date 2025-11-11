function isSafeHTML(html) {
    if (html === null || html === undefined || typeof html !== 'string') {
        return true;
    }
    
    const dangerousTags = ['<script', '<iframe', '<object'];
    
    for (let tag of dangerousTags) {
        if (html.toLowerCase().includes(tag)) {
            return false;
        }
    }
    
    return true;
}