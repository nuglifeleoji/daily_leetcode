package priority_queue;
import java.util.*;

class Twitter {
    private static class Tweet {
        int time;
        int id;
        Tweet(int time, int id) { this.time = time; this.id = id; }
    }

    private static class Node {
        int user;
        int idx;   
        int time;
        int id;
        Node(int user, int idx, int time, int id) {
            this.user = user;
            this.idx = idx;
            this.time = time;
            this.id = id;
        }
    }

    private int time = 0;
    private Map<Integer, Set<Integer>> following = new HashMap<>();
    private Map<Integer, List<Tweet>> tweets = new HashMap<>();

    private void initUser(int u) {
        following.computeIfAbsent(u, k -> {
            Set<Integer> s = new HashSet<>();
            s.add(u);        
            return s;
        });
        tweets.computeIfAbsent(u, k -> new ArrayList<>());
    }

    public Twitter() {}

    public void postTweet(int userId, int tweetId) {
        initUser(userId);
        tweets.get(userId).add(new Tweet(time++, tweetId));
    }

    public List<Integer> getNewsFeed(int userId) {
        if (!following.containsKey(userId)) return new ArrayList<>();
        initUser(userId);
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> b.time - a.time);
        for (int f : following.get(userId)) {
            List<Tweet> list = tweets.get(f);
            if (list == null || list.isEmpty()) continue;
            int idx = list.size() - 1;
            Tweet t = list.get(idx);
            pq.offer(new Node(f, idx, t.time, t.id));
        }

        List<Integer> res = new ArrayList<>();
        while (!pq.isEmpty() && res.size() < 10) {
            Node cur = pq.poll();
            res.add(cur.id);
            int nextIdx = cur.idx - 1;
            if (nextIdx >= 0) {
                Tweet t = tweets.get(cur.user).get(nextIdx);
                pq.offer(new Node(cur.user, nextIdx, t.time, t.id));
            }
        }
        return res;
    }

    public void follow(int followerId, int followeeId) {
        initUser(followerId);
        initUser(followeeId);
        following.get(followerId).add(followeeId);   
    }

    public void unfollow(int followerId, int followeeId) {
        if (!following.containsKey(followerId)) return;
        if (followeeId == followerId) return; 
        following.get(followerId).remove(followeeId);
    }
}