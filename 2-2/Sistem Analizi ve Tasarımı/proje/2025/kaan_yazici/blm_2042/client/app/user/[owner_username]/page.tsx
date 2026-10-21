import UserPage from './userPage'

export default async function Home(props: { params: Promise<{ owner_username: string}> }) {
  const {owner_username} = await props.params;

  return <UserPage username={owner_username} />
}