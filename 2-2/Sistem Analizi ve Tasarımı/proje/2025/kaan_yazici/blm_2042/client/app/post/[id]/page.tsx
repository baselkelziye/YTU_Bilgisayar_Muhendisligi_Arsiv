import PostPage from './postPage';

export default async function PostDetailPage(props: { params: Promise<{ id: string }> }) {
    const { id } = await props.params;

    return <PostPage id={id}/>;
}
