import { NextResponse } from 'next/server';
import type { NextRequest } from 'next/server';

export function middleware(request: NextRequest) {
  const { pathname } = request.nextUrl;
  const authToken = request.cookies.get('JSESSIONID');

  const isPublicRoute = pathname === '/signin' || pathname === '/signup';
  const isApiRoute = pathname.startsWith('/api');

  if (!authToken && !isPublicRoute && !isApiRoute) {
    return NextResponse.redirect(new URL('/signin', request.url));
  }

  return NextResponse.next();
}

export const config = {
  matcher: ['/((?!_next/static|_next/image|favicon.ico|signin|signup|api).*)'],
};
