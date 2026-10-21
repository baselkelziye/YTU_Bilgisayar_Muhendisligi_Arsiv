import CommunityPage from './communityPage';

export default async function CommunityDetailPage(props: { params: Promise<{ id: string }> }) {
  const { id } = await props.params;

  return <CommunityPage id={id} />;
}
