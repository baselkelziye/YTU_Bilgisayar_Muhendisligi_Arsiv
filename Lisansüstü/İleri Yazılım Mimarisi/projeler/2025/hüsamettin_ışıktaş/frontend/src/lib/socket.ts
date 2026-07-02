import { io, Socket } from 'socket.io-client';

class SocketService {
  private socket: Socket | null = null;
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  private listeners: Map<string, ((...args: any[]) => void)[]> = new Map();

  connect(token: string) {
    if (this.socket) {
      return;
    }

    // Connect to the websocket gateway
    // Use window.location.hostname for remote connections
    const wsUrl = import.meta.env.VITE_WS_URL || `http://${window.location.hostname}:3006`;
    this.socket = io(wsUrl, {
      auth: { token },
      path: '/socket.io',
      transports: ['websocket', 'polling'],
    });

    this.socket.on('connect', () => {
      console.log('Socket connected');
    });

    this.socket.on('disconnect', () => {
      console.log('Socket disconnected');
    });

    // Listen to all events and dispatch to internal listeners
    this.socket.onAny((event, ...args) => {
      console.log(`Socket event received: ${event}`, args);
      this.emitInternal(event, ...args);
    });
  }

  disconnect() {
    if (this.socket) {
      this.socket.disconnect();
      this.socket = null;
    }
  }

  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  on(event: string, callback: (...args: any[]) => void) {
    if (!this.listeners.has(event)) {
      this.listeners.set(event, []);
    }
    const callbacks = this.listeners.get(event) || [];
    // Prevent duplicate callbacks
    if (!callbacks.includes(callback)) {
      callbacks.push(callback);
      this.listeners.set(event, callbacks);
    }
  }

  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  off(event: string, callback: (...args: any[]) => void) {
    const callbacks = this.listeners.get(event);
    if (callbacks) {
      this.listeners.set(
        event,
        callbacks.filter((cb) => cb !== callback)
      );
    }
  }

  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  private emitInternal(event: string, ...data: any[]) {
    console.log(`Emitting internal event: ${event}`, data);
    const callbacks = this.listeners.get(event);
    if (callbacks) {
      console.log(`Calling ${callbacks.length} callbacks for event: ${event}`);
      callbacks.forEach((cb) => cb(...data));
    } else {
      console.log(`No listeners registered for event: ${event}`);
    }
  }

  getSocket() {
      return this.socket;
  }
}

export const socketService = new SocketService();
