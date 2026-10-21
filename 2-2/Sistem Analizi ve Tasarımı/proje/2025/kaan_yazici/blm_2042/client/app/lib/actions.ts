export function slugify(name: string): string {
  return encodeURIComponent(name.trim());
}

export function deslugify(encodedName: string): string {
  return decodeURIComponent(encodedName);
}